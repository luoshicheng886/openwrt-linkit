#
# Copyright (C) 2011-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sys-clock
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/sys-clock
  SECTION:=extra
  CATEGORY:=Extra packages
  TITLE:=Clock for LCM1602 display
  DEPENDS:=+libupm-i2clcd
  MAINTAINER:=Steven Luo <steven.lo@efctw.com>
endef

define Package/sys-clock/description
 The HD44780 is one of the most popular character LCDs ever made,
 with numerous third-party displays utilizing its 16-pin interface
 and instruction set for compatibility.
 The PCF8574 chip is used in the I2C module on the back of the LCD.
endef

define Build/Prepare
	$(INSTALL_DIR) $(PKG_BUILD_DIR)
	$(INSTALL_DATA) ./src/* $(PKG_BUILD_DIR)/
endef

TARGET_CXXFLAGS += \
	-I$(STAGING_DIR)/usr/include

TARGET_LDFLAGS += -lupm-i2clcd

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CXX="$(TARGET_CXX)" \
		CXXFLAGS="$(TARGET_CXXFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/sys-clock/install
	$(INSTALL_DIR) $(1)/usr/sbin $(1)/etc/init.d
	$(INSTALL_BIN) ./files/lcd-time.init $(1)/etc/init.d/lcd-time
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lcd-time $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,sys-clock))
