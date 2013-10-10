#!/usr/bin/perl

use File::Slurp;
open(MYFILE, ">>textures.txt");
my $file = read_file("textures.txt");

$str = scalar @ARGV;
printf "$str\n";
for($i=0; $i<scalar @ARGV; $i++) {
	if(-e "resources/$ARGV[$i]") {
		print "File: $ARGV[$i] found\n";
		if(index($file, $ARGV[$i]) >= 0) {
			print "File: already contains $ARGV[i]\n\n";
		} else {
			print "File: added $ARGV[$i]\n\n";
			$rowlength = 60;
			print MYFILE "resources/$ARGV[$i]";
			$rowlength = $rowlength - length("resources/$ARGV[$i]");
			for($j=0; $j<$rowlength; $j++) {
				print MYFILE " ";
			}
			$ARGV[$i] =~ s/.png//;
			print MYFILE "$ARGV[$i]\n";
		}
	} else {
		print "File: $ARGV[$i] not found";
	}
}
