#
# bcloud default makefile
# more details please refer to ./.bcloud.cache/makefile.*
#
.SILENT:

#
#makefile-self location, must be always on the top!!!
#
MAKEFILE_PATH_DEFAULT := $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))
MAKEFILE_DIR_DEFAULT := $(shell cd $(dir $(MAKEFILE_PATH_DEFAULT)) && pwd)

MAKEFILE_DEAULT := 'imported'

#
#Global Configs
#
WORK_ROOT := $(shell cd $(MAKEFILE_DIR_DEFAULT)/../../.. && pwd)
GCC_PATH := /opt/compiler/gcc-4.8.2/bin

#
#import global configs
#
ifneq ($(MAKEFILE_CONFIG), 'imported')
    include $(MAKEFILE_DIR_DEFAULT)/.bcloud.cache/makefile.config
endif

.PHONEY: all clean distclean cleanall help
all: main

clean:
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/\*.o ...
	find $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21 -name "*.o" | xargs rm -rf
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/bin ...
	rm -rf $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/bin
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/lib ...
	rm -rf $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/lib
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/so ...
	rm -rf $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/so
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/test ...
	rm -rf $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/test
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output

distclean:
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile.baidu_goodcoder_liuyuan21 ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile.baidu_goodcoder_liuyuan21
	echo removing $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21 ...
	rm -rf $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output
	echo -e '\033[32m[NOTICE]\033[0m'
	echo -e \\tplease run \'bcloud local -M\' before next \'make\'!!!

cleanall:
	echo removing $(WORK_ROOT)/bc_out ...
	rm -rf $(WORK_ROOT)/bc_out
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile
	echo removing $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile\* ...
	rm -rf $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile*
	echo -e '\033[32m[NOTICE]\033[0m'
	echo -e \\tplease run \'bcloud local or bcloud local -M ALL\' before next \'make\'!!!

baidu/third-party/gtest: baidu/third-party/gtest_deps

third-64/gtest: third-64/gtest_deps

third-64/glog: third-64/glog_deps

third-64/boost: third-64/boost_deps

baidu/third-party/glog: baidu/third-party/glog_deps

baidu/third-party/boost: baidu/third-party/boost_deps

help:
	echo -e 'all available targets of make($(MAKE_VERSION)):\n'
	echo '    all              : will compile all targets and run release.bcloud'
	echo '    no-release.bcloud: will compile all targets and not run release.bcloud'
	echo '    no-ut            : will compile all targets without ut and run release.bcloud'
	echo '    test             : will compile all targets, run ut and run release.bcloud'
	echo '    clean            : will only cleanup Intermediate files (such as .o, .so, .a, ut and bin) of main module:'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/bin'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/lib'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/so'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/\*.o'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21/output/test'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output'
	echo '    distclean        : will cleanup makefile, intermediate files(such as .o, .so, .a, ut and bin) and pb.cc/pb.h idl.h/idl.cpp of main module:'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile.baidu_goodcoder_liuyuan21'
	echo '                       $(WORK_ROOT)/bc_out/baidu/goodcoder/liuyuan21'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output'
	echo '    cleanall         : will cleanup makefiles, intermediate files(such as .o, .so, .a, ut and bin) and pb.cc/pb.h idl.h/idl.cpp of all modules:'
	echo '                       $(WORK_ROOT)/bc_out'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/output'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/Makefile'
	echo '                       $(WORK_ROOT)/baidu/goodcoder/liuyuan21/.bcloud.cache/makefile*'
	echo '    help             : list all available make targets'
	echo -e '\ntargets for the compile of dependency module:'
	echo '    baidu/third-party/boost'
	echo '    baidu/third-party/glog'
	echo '    baidu/third-party/gtest'
	echo '    third-64/boost'
	echo '    third-64/glog'
	echo '    third-64/gtest'



#
#import dependency modules
#
ifneq ($(MAKEFILE_BAIDU_GOODCODER_LIUYUAN21), 'imported')
    include $(MAKEFILE_DIR_DEFAULT)/.bcloud.cache/makefile.baidu_goodcoder_liuyuan21
endif
