<?php
	for($i=0;$i<5;$i++){
		$s = trim(fgets(STDIN));
		if($s=="yes")$yes++;
		else $no++;
	}
	if($yes>$no)echo "yes";
	else echo "no";
?>
