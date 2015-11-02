'use strict'
var db = require('mongoskin').db('mongodb://localhost:27017/test');

var getbook = function(isbn){
	return new Promise(function(resolve, reject){
		var books = db.collection('books');
		var res = books.find({"isbn": isbn}).limit(1);
		res.toArray(function(err, arr){
			if(!err){
				resolve(arr);
			}
			else{
				reject("Something went wrong");
			}
			db.close();
		});
	});
};

var newentry = function(book) {
	var books = db.collection('books');
	var res = books.insert(book);
	db.close();
	return res;
};

var findbook = function(querry, type){
	var promise;
	if(type === "title"){
		promise = new Promise(function(resolve, reject){
			var books = db.collection('books');
			var res = books.find({"title": "/" + querry +"/"});
			res.toArray(function(err, arr){
				if(!err){
					resolve(arr);
				}
				else{
					reject("Something went wrong");
				}
				db.close();
			});
		});
	}
	else if(type == "author"){
		promise = new Promise(function(resolve, reject){
			var books = db.collection('books');
			var res = books.find({"author": "/" + querry +"/"});
			res.toArray(function(err, arr){
				if(!err){
					resolve(arr);
				}
				else{
					reject("Something went wrong");
				}
				db.close();
			});
		});
	}
	else{
		promise = getbook(querry);
	}
	return promise;
};

module.exports = {
	getbook: getbook,
	newentry: newentry,
	findbook: findbook
};

process.on('SIGINT', function() {
    console.log('Recieve SIGINT');
    db.close(function(){
        console.log('database connection has been closed.');
        process.exit();
    });
})