<?php
	fscanf(STDIN, "%d %d %d %d\n", $x, $y, $z, $q);
	$xl = [0,$x];
	$yl = [0,$y];
	while($q--){
		fscanf(STDIN, "%d %d\n", $d, $a);
		if($d == 0) $xl[] = $a;
		else $yl[] = $a;
	}
	sort($xl);
	sort($yl);
	$xmin = 100000000;
	for($i=0;$i<count($xl)-1;$i++) $xmin = min($xmin,$xl[$i+1]-$xl[$i]);
	$ymin = 100000000;
	for($i=0;$i<count($yl)-1;$i++) $ymin = min($ymin,$yl[$i+1]-$yl[$i]);
	echo $xmin*$ymin*$z;
?>
