
<div>
	<table>
	
		<tr>
			<th>Action</th>
			<th>Symbol</th>   
			<th>Shares</th>
			<th>Price of a share</th>				
			<th>When</th>	
		</tr>
		
	<?php
		
		$i = 0;
		if ($positions == NULL) {
			echo "You haven't done anything yet.";
		} else {				
			foreach($positions as $position) {		
				$stock = lookup($positions[$i]["symbol"]);
				$price = number_format($stock["price"], 2);	
				print("<tr>");
				print("<td>{$position["type"]}</td>");
				print("<td> {$position["symbol"]}</td>");
				print("<td>{$position["shares"]}</td>");
				print("<td>$ {$price}</td>");
				print("<td>{$positions[$i]["date"]}</td>");
				print("</tr>");
				$i++;
		}                    
	}
	?>
	</table>
</div>

