var	express = require('express'),
	router = express.Router(),
	users = require('../models/users'),
	scrypt = require('scrypt');

router.get('/', function(req, res, next) {
	if(req.user){
		res.redirect('/dashboard');
	}
	else{
		res.render('login', {title: 'Login'});
	}
});

router.post('/', function(req, res){
	var email = req.body.email;
	var pass = req.body.password;
	var promise = users.getuser(email);
	promise.then(function(result){
		if(result.length === 0){
			res.render('login', {title: 'Login', error: "Invalid email or password (not found)"});			
		}
		else{
			var isvalid = scrypt.verifyKdfSync(result[0].pass.buffer, pass);
			if(isvalid){
				req.session.email = email;
				res.redirect('/dashboard');
			}
			else{
				res.render('login', {title: 'Login', error: 'Invalid email or password (wrong pass)'});
			}
		}
	}).catch(function(err){
		res.render('login', {title: 'Login', error: err.toString()});
	});
});

module.exports = router;