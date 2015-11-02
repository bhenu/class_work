var express = require('express');
var router = express.Router();
var requireLogin = require('../middleware').requireLogin;
var ifAdmin = require('../middleware').ifAdmin;
var books = require('../models/books');

router.get('/', requireLogin, ifAdmin, function(req, res) {
	res.render('admin');
});

router.get('/manage-books', requireLogin, ifAdmin, function(req, res){
	res.render('manage-books');
});

router.get('/manage-books/add', requireLogin, ifAdmin, function(req, res){
	res.render('add-book');
});

router.post('/manage-books/add', requireLogin, ifAdmin, function(req, res){
	var book = {};
	book.title = req.body.title;
	book.isbn  = req.body.isbn;
	book.authors = req.body.authors;
	book.publisher = req.body.publisher;
	book.subject = req.body.subject;
	book.notes = req.body.notes;
	book.shelf = req.body.shelf;
	book.ncopies = req.body.ncopies;
	var promise = books.getbook(book.isbn);
	promise.then(function(result){
		console.log(result);
		if(result.length === 0){
			books.newentry(book);
			res.redirect('/admin/manage-books');
		}
		else{
			res.render('add-book', {error: "The book already exists!"});
		}
	}).catch(function(err){
		res.render('add-book', {error: err});
	});
});

module.exports = router;