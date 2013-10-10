#!/usr/bin/perl

print scalar @ARGV;
if(-e $ARGV[0]) {
	print "found";
}
