<?php
	fscanf(STDIN, "%d %d\n", $c1, $p1);
	fscanf(STDIN, "%d %d\n", $c2, $p2);
	if($c1*$p2>$c2*$p1) echo 1;
	else echo 2;
?>
