<?php
	require("../includes/config.php");
	
	if($_SERVER["REQUEST_METHOD"] == "POST") {
		if (empty($_POST["password"])){
				apologize("You left a field empty.");
		}	
			
		if(empty($_POST["confirmation"])) {
				apologize("You left a field empty");
		}

		if($_POST["password"] != $_POST["confirmation"]){
				apologize("The passwords don't match.");
		} else {
			$rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
			query("UPDATE users set hash = ? WHERE id = ?", crypt($_POST["password"]), $_SESSION["id"]);
			redirect("index.php");
		}
	}


	render("../templates/settings_template.php", ["title" => "Settings"]);


?>
