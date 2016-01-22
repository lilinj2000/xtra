AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

noinst_PROGRAMS = unittest

unittest_SOURCES = \
	TraderServiceImplTest.cc


unittest_CPPFLAGS = -I$(top_srcdir) -I.. -I..\
		$(BOOST_CPPFLAGS) \
		$(XELE_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(SOIL_CPPFLAGS)


unittest_LDADD = \
	$(GTEST_LIBADD) \
	../service/libxtra.la \
	$(BOOST_LIBADD) \
	$(XELE_LIBADD) \
	$(SOIL_LIBADD)



unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh xtra.cfg log.cfg

