#!/usr/bin/env python

from nose.tools import *
from subprocess import call
import os

#import os, sys, glob, mapnik2

def test():
    # mapnik-config program
    # should be on default path...
    mc = 'mapnik-config'
    valid = ['--help',
             '--prefix',
             '--exec-prefix',
             '--libs',
             '--cflags',
             '--fonts',
             '--input-plugins',
             '-v',
             '--version',
             '--svn-revision',
    ]

    # valid args should return 1
    for item in valid:
        eq_(0,call([mc,item]))
    
    # errors should return 1
    eq_(1,call([mc,'']))
    eq_(1,call([mc,'foo']))