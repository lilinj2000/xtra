AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libxtra.la
libxtra_la_SOURCES = \
		TraderOptions.cc TraderSpiImpl.cc \
		TraderServiceImpl.cc

libxtra_la_CPPFLAGS = -I$(top_srcdir) \
			$(BOOST_CPPFLAGS) \
			$(XELE_CPPFLAGS) \
			$(RAPIDJSON_CPPFLAGS) \
			$(FMT_CPPFLAGS) \
			$(SPDLOG_CPPFLAGS) \
			$(SOIL_CPPFLAGS)

libxtra_la_LIBADD = $(XELE_LIBADD) \
		$(BOOST_LIBADD) \
		$(FMT_LIBADD) \
		$(SOIL_LIBADD)

libxtra_la_LDFLAGS = \
	-no-undefined -version-info \
	$(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE)

# header files
noinst_HEADERS = \
	TraderOptions.h \
	TraderServiceImpl.h \
	TraderSpiImpl.h \
	CXeleFtdcUserApiStructPrint.h


