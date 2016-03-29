<?php
	$n = fgets(STDIN);
	for ($i=0; $i < $n; $i++) { 
		$k = fgets(STDIN);
		echo date("H:i\n",mktime(1,0,0)-$k/3*60);
	}
?>
