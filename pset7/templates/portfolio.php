<div>
	<?php
		$cash = $balance[0]["cash"];
		$cash = number_format($cash, 2);
	?>

	<b><?= ("Balance: $ ".$cash); ?></b>
	<br/>
	
	<table>	
		<tr>
			<th>Name</th>
			<th>Symbol</th>   
			<th>Price</th>
			<th>Shares</th>
			<th>Value</th>
		</tr>
		
		<?php
		
		foreach ($positions as $position) {
            $value = $position["price"] * $position["shares"];
            $value = number_format($value, 2);
            
            $position["price"] =  number_format($position["price"], 2);
           
            print("<tr>");
            print("<td>{$position["name"]}</td>");
            print("<td> {$position["symbol"]}</td>");
            print("<td>{$position["price"]}</td>");
            print("<td>{$position["shares"]}</td>");
            print("<td>$ {$value}</td>");

            print("</tr>");
        }
                     
	?>
	</table>
</div>

