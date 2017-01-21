/*select all authors,their books and store name, where it can be found*/
select title,author_name,store_name,store_address 
	from authorof,edition,price
	where authorof.isbn=edition.isbn and authorof.isbn=price.isbn;
/*select all stores where can be found 'Calculus'*/
select store_name,store_address,price 
	from edition,price 
	where title='Calculus with Analytic Geometry' and edition.isbn=price.isbn;
/*select all books that have been printed by 'Prentice-Hall' and store where they can be found*/
select title,store_name,price 
	from price,publisherof,edition
	where (publisherof.isbn=price.isbn and publisherof.isbn=edition.isbn) 
		and publisher_name='Prentice-Hall';
/*select all authors that have been published by 'McGraw-Hill'*/
select author_name,title,pub_date
	from authorof,edition
	where authorof.isbn in
	(select publisherof.isbn
		from publisherof
		where publisher_name='McGraw-Hill') and edition.isbn=authorof.isbn;
/*select all books of 'Richard Stevens' and stores where they can be found*/
select title,store_name,price
	from price,edition
	where price.isbn in
	(select authorof.isbn 
		from authorof
		where author_name='Richard Stevens') and price.isbn=edition.isbn;
/*select all editions of 'Partial Differential Equations' and their publishers*/
select num,pub_date,publisher_name,publisher_address
	from edition,publisherof
	where edition.isbn=publisherof.isbn and title='Partial Differential Equations';
/*select all authors that lives in 'New York' but published their books not in 'New York'*/
select author_name,author_address,publisher_name,publisher_address
	from publisherof,authorof
	where author_address='New York' and publisher_address<>'New York' 
		and authorof.isbn=publisherof.isbn;
/*select all stores where can be found 'Partial Differential Equations' 
or 'Elementary Differential Equations'
with price less than 200.00*/
select title,store_name,store_address,price 
	from price,edition
	where (price.isbn,edition.title) in
	(select edition.isbn,edition.title
		from edition
		where title='Partial Differential Equations' 
			or title='Elementary Differential Equations') and price<=200.00;

/*inserts*/
insert into edition
	values(7777,'A First Course in Database Systems','Ullman',3,to_date('1999-25-03','YYYY-DD-MM'));
insert into publisher
	values('Morgan-Kaufmann','San Francisco');
insert into authorof(isbn,author_name,author_address)
	select distinct 7777,author_name,author_address
		from edition,authorof
		where title='A First Course in Database Systems' and edition.isbn=authorof.isbn;
insert into publisherof(isbn,publisher_name,publisher_address)
	select distinct 7777,publisher_name,publisher_address
		from edition,publisherof
		where title='A First Course in Database Systems' and edition.isbn=publisherof.isbn;

/*deletes*/
delete from store
	where name='Best Printings';
delete from edition
	where num=1 and isbn<4444;

/*updates*/
update edition
	set num=3
	where title='UNIX Network Programming';
update price
	set price=price+0.2*price
	where isbn in
		(select isbn 
			from edition
			where title='A First Course in Database Systems');

/*views*/
create view calculus as
	select store_name,store_address,price 
		from edition,price 
		where title='Calculus with Analytic Geometry' and edition.isbn=price.isbn;
create view stevens_books as
	select title,store_name,store_address,price
		from price,edition
		where price.isbn in
		(select authorof.isbn 
			from authorof
			where author_name='Richard Stevens') and price.isbn=edition.isbn;
create view editions as
	select num,pub_date,publisher_name,publisher_address
		from edition,publisherof
		where edition.isbn=publisherof.isbn and title='A First Course in Database Systems';
select * from calculus;
select * from stevens_books;
select * from editions;