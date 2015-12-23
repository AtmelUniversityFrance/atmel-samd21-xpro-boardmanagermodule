#
#  Atmel SAMD21/R21/W25 Xplained Pros Arduino IDE Module makefile.
#
#  Copyright (c) 2015 Atmel Corp./Thibaut VIARD. All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#

SHELL = /bin/sh

.SUFFIXES: .tar.bz2

ROOT_PATH := .
VARIANTS_PATH := $(ROOT_PATH)/module/variants

# Variant list, can be overriden via command line or ENV
VARIANTS?=$(shell ls --hide=*.mk $(VARIANTS_PATH))

ifeq ($(TRAVIS),true)
PRINT_INFO_TRAVIS=print_info_travis
else
PRINT_INFO_TRAVIS=
endif

CORE_VERSION := $(shell grep version= $(ROOT_PATH)/module/platform.txt | sed 's/version=//g')
PACKAGE_NAME := $(basename $(notdir $(CURDIR)))

# -----------------------------------------------------------------------------
# packaging specific
PACKAGE_FOLDER := module

ifeq (postpackaging,$(findstring $(MAKECMDGOALS),postpackaging))
  PACKAGE_FILENAME=$(PACKAGE_NAME)-$(CORE_VERSION).tar.bz2
  PACKAGE_CHKSUM := $(firstword $(shell sha256sum "$(PACKAGE_FILENAME)"))
  PACKAGE_SIZE := $(firstword $(shell wc -c "$(PACKAGE_FILENAME)"))
endif

# end of packaging specific
# -----------------------------------------------------------------------------

.PHONY: all clean print_info print_info_travis postpackaging

# Arduino module packaging:
#   - exclude version control system files, here git files and folders .git, .gitattributes and .gitignore
#   - exclude 'extras' folder
#   - exclude 'obj' folder from variants
all: clean print_info $(PRINT_INFO_TRAVIS)
	@echo ----------------------------------------------------------
	@echo "Packaging module."
	tar --transform "s|module|$(PACKAGE_NAME)-$(CORE_VERSION)|g" --exclude=.gitattributes --exclude=.travis.yml --exclude-vcs --exclude=obj -cjf "$(PACKAGE_NAME)-$(CORE_VERSION).tar.bz2" "$(PACKAGE_FOLDER)"
	$(MAKE) --no-builtin-rules postpackaging -C .
	@echo ----------------------------------------------------------

clean:
	@echo ----------------------------------------------------------
	@echo  Cleanup
	-$(RM) $(PACKAGE_NAME)-*.tar.bz2 package_$(PACKAGE_NAME)_*.json test_package_$(PACKAGE_NAME)_*.json
	@echo ----------------------------------------------------------

print_info:
	@echo ----------------------------------------------------------
	@echo Building $(PACKAGE_NAME) using
	@echo "CURDIR             = $(CURDIR)"
	@echo "OS                 = $(OS)"
	@echo "SHELL              = $(SHELL)"
	@echo "VARIANTS_PATH      = $(VARIANTS_PATH)"
	@echo "VARIANTS           = $(VARIANTS)"
	@echo "OPTIBOOT_VARIANTS  = $(OPTIBOOT_VARIANTS)"
	@echo "CORE_VERSION       = $(CORE_VERSION)"
	@echo "PACKAGE_NAME       = $(PACKAGE_NAME)"
#	"$(CC)" -v
#	env

print_info_travis:
	@echo ----------------------------------------------------------
	@echo Travis-CI envvars
	@echo "TRAVIS_OS_NAME      = $(TRAVIS_OS_NAME)"
	@echo "TRAVIS_LANGUAGE     = $(TRAVIS_LANGUAGE)"
	@echo "TRAVIS_REPO_SLUG    = $(TRAVIS_REPO_SLUG)"
	@echo "TRAVIS_BRANCH       = $(TRAVIS_BRANCH)"
	@echo "TRAVIS_TAG          = $(TRAVIS_TAG)"
	@echo "TRAVIS_PULL_REQUEST = $(TRAVIS_PULL_REQUEST)"
	@echo "TRAVIS_COMMIT       = $(TRAVIS_COMMIT)"
	@echo "TRAVIS_COMMIT_RANGE = $(TRAVIS_COMMIT_RANGE)"
	@echo "TRAVIS_JOB_ID       = $(TRAVIS_JOB_ID)"
	@echo "TRAVIS_JOB_NUMBER   = $(TRAVIS_JOB_NUMBER)"
	@echo "TRAVIS_BUILD_DIR    = $(TRAVIS_BUILD_DIR)"
	@echo "TRAVIS_BUILD_ID     = $(TRAVIS_BUILD_ID)"
	@echo "TRAVIS_BUILD_NUMBER = $(TRAVIS_BUILD_NUMBER)"

# sed s/%%PR_NUMBER%%/$(TRAVIS_JOB_NUMBER)/ | sed s/%%BUILD_NUMBER%%/$(TRAVIS_BUILD_NUMBER)/ |sed s/%%VERSION%%/$(CORE_VERSION)-build-$(TRAVIS_BUILD_NUMBER)/
postpackaging:
	@echo "PACKAGE_CHKSUM      = $(PACKAGE_CHKSUM)"
	@echo "PACKAGE_SIZE        = $(PACKAGE_SIZE)"
	@echo "TRAVIS_JOB_NUMBER   = $(TRAVIS_JOB_NUMBER)"
	@echo "TRAVIS_BUILD_NUMBER = $(TRAVIS_BUILD_NUMBER)"
	@echo "PACKAGE_FILENAME    = $(PACKAGE_FILENAME)"
	cat extras/package_index.json.template | sed s/%%VERSION%%/$(CORE_VERSION)/ | sed s/%%FILENAME%%/$(PACKAGE_FILENAME)/ | sed s/%%CHECKSUM%%/$(PACKAGE_CHKSUM)/ | sed s/%%SIZE%%/$(PACKAGE_SIZE)/ > package_$(PACKAGE_NAME)_$(CORE_VERSION)_index.json
	cp package_$(PACKAGE_NAME)_$(CORE_VERSION)_index.json test_package_$(PACKAGE_NAME)_$(CORE_VERSION)_index.json
	@echo "package_$(PACKAGE_NAME)_$(CORE_VERSION)_index.json created"
