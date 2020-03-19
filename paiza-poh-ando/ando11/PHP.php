<?php
	$n = trim(fgets(STDIN));
	for($i=0;$i<$n;$i++){
		$q[$i] = explode(" ",trim(fgets(STDIN)));
	}
	$m = trim(fgets(STDIN));
	for($i=0;$i<$n;$i++){
		$p[$i] = explode(" ",trim(fgets(STDIN)));
	}
	for($i=0;$i<=$n-$m;$i++){
		for($j=0;$j<=$n-$m;$j++){
			$find=true;
			for($k=0;$k<$m;$k++){
				for($l=0;$l<$m;$l++){
					if($q[$i+$k][$j+$l]!=$p[$k][$l]){
						$find=false;
						break 2;
					}
				}
			}
			if($find){
				echo $i." ".$j;
				break 2;
			}
		}
	}
?>
