drop table author cascade constraints;
drop table edition cascade constraints;
drop table publisher cascade constraints;
drop table store cascade constraints;
drop table price cascade constraints;
drop table publisherof cascade constraints;
drop table authorof cascade constraints;

create table author(
	name varchar2(30) not null,
	address varchar2(20) not null,
	primary key (name,address)
);

create table publisher(
	name varchar2(30) not null,
	address varchar2(20) not null,
	primary key (name,address)
);

create table edition(
	isbn number(4) not null,
	title varchar2(60) not null,
	copyright varchar2(15) default null,
	num number(2) default 1,
	pub_date date default null,
	primary key (isbn)
);

create table store(
	name varchar2(30) not null,
	address varchar2(20) not null,
	primary key (name,address)
);

create table price(
	isbn number(4) not null,
	store_name varchar2(30) not null,
	store_address varchar2(20) not null,
	price number(7,2) not null,
	primary key(isbn,store_name,store_address),
	foreign key(isbn) references edition(isbn)  
		on delete cascade,
	foreign key(store_name,store_address) references store(name,address) 
		on delete cascade 
);

create table authorof(
	isbn number(4) not null,
	author_name varchar2(30) not null,
	author_address varchar2(20) not null,
	primary key(isbn,author_name,author_address),
	foreign key(isbn) references edition(isbn)
		on delete cascade,
	foreign key(author_name,author_address) references author(name,address)
		on delete cascade
);

create table publisherof(
	isbn number(4) not null,
	publisher_name varchar2(30) not null,
	publisher_address varchar2(20) not null,
	primary key(isbn,publisher_name,publisher_address),
	foreign key(isbn) references edition(isbn)
		on delete cascade,
	foreign key(publisher_name,publisher_address) references publisher(name,address)
		on delete cascade
);