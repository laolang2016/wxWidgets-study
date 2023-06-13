#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys 
import os
from shutil import copyfile

wx_env_name='wx_win'

dll_dict={
    # 'wxbase322u':'net',
    'wxbase322u':'',
    # 'wxbase322u':'xml',

    # 'wxmsw322u':'adv',
    # 'wxmsw322u':'aui',
    'wxmsw322u':'core',
    # 'wxmsw322u':'gl',
    # 'wxmsw322u':'html',
    # 'wxmsw322u':'media',
    # 'wxmsw322u':'propgrid',
    # 'wxmsw322u':'qa',
    # 'wxmsw322u':'ribbon',
    # 'wxmsw322u':'richtext',
    # 'wxmsw322u':'stc',
    # 'wxmsw322u':'webview',
    # 'wxmsw322u':'xrc'
}


if __name__ == "__main__":
    platform = sys.argv[1]
    configuration = sys.argv[2]
    proj_dir = sys.argv[3]
    wx_path = os.getenv(wx_env_name)

    # print('wx_path:',wx_path)
    # print('platform:', platform)
    # print('configuration:',configuration)
    # print('proj_dir:',proj_dir)

    for key,value in dll_dict.items():
        dll_name = key
        if 'Debug' == configuration:
            dll_name = dll_name + 'd'
        if 0 == len(value):
            dll_name = dll_name + '_vc_'
        else:
            dll_name = dll_name + '_' + value + '_vc_'
        if 'x64' == platform:
            dll_name = dll_name + 'x64_'
        dll_name = dll_name + 'custom.dll'
        # print('dll_name:',dll_name)
        
        source_dll = wx_path + os.path.sep + 'lib'
        if 'x64' == platform:
            source_dll = source_dll + os.path.sep + 'vc_x64_dll' + os.path.sep + dll_name
        else:
            source_dll = source_dll + os.path.sep + 'vc_dll' + os.path.sep + dll_name
        # print('source_dll',source_dll)
        target_dll = proj_dir + os.path.sep + platform + os.path.sep + configuration  +  os.path.sep + dll_name
        # print('target_dll',target_dll)
        print(source_dll + ' => ' + target_dll)
        if not os.path.exists(target_dll):
            copyfile(source_dll, target_dll)
        

    