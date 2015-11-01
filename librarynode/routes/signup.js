var express = require('express'),
	router = express.Router(),
	users = require('../models/users'),
	email_validator = require('email-validator');

/* Show the sign up page */
router.get('/', function(req, res, next) {
	res.render('signup', {title: 'Sign Up'});
});

/* Create new accoutn */
router.post('/', function(req, res, next) {
	var email = req.body.email;
	var pass = req.body.password;
	var retype = req.body.retype;
	if(!email_validator.validate(email)){
		res.render('signup', {title: 'Sign up', error: "Invalid email address."});
	}
	else{
		var promise = users.getuser(email);
		promise.then(function(result){
			if(result.length === 0){
				if(pass != retype){
					res.render('signup', {title: 'Sign up', error: "Passwords didnot match."});
				}
				else{
					users.createuser(email, pass);
					res.redirect('/?message=signupsucc');
				}
			}
			else{
				res.render('signup', {title: 'Sign up', error: "User exists! -_-"});
			}
		}).catch(function(err){
			res.render('signup', {title: 'Sign up', error: err.toString()});
		});
	}
});

module.exports = router;
