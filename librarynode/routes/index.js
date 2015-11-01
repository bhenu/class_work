var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
	if(req.session.email){
		res.render('home', { title: 'Home', message: req.session.email});
	}
	else if(req.query.message === 'signupsucc'){
		res.render('home', { title: 'Home', message: 'Signup successful. You can login now.'});
	}
	else{
		res.render('home', { title: 'Home' });
	}
});

router.get('/logout', function(req, res, next){
	req.session.destroy();
	res.redirect('/');
});

module.exports = router;
