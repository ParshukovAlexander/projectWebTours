Action()
{
	lr_start_transaction("allTime");

	lr_start_transaction("goto_project");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=<title>Web Tours</title>",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("goto_project",LR_AUTO);

	lr_start_transaction("registration");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(16);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("registration",LR_AUTO);
	
	lr_start_transaction("registratinon_form");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(51);


	lr_save_string(lr_eval_string("{alphabet}{alphabet}{alphabet}{alphabet}{alphabet}{alphabet}"),"rnd_login" );
	lr_save_string(lr_eval_string("{alphabet}{alphabet}{alphabet}{alphabet}{alphabet}{alphabet}"),"rnd_password" );
	
	web_reg_find("Text=We hope we can meet all your current and future travel needs. ",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={rnd_login}", ENDITEM, 
		"Name=password", "Value={rnd_password}", ENDITEM, 
		"Name=passwordConfirm", "Value={rnd_password}", ENDITEM, 
		"Name=firstName", "Value=firstName", ENDITEM, 
		"Name=lastName", "Value=lastName", ENDITEM, 
		"Name=address1", "Value=street", ENDITEM, 
		"Name=address2", "Value=state", ENDITEM, 
		"Name=register.x", "Value=58", ENDITEM, 
		"Name=register.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("registratinon_form",LR_AUTO);
	
	lr_start_transaction("registration_next_page");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(8);
	
	web_reg_find("Text=User has returned to the home page",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("registration_next_page",LR_AUTO);
	
		lr_start_transaction("logout");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(32);

	web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("allTime",LR_AUTO);


	return 0;
}