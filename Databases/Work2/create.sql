drop table supplier cascade constraint;
drop table item cascade constraint;
drop table quantity cascade constraint;
drop table orders cascade constraint;
drop table orderedby cascade constraint;
drop table cardof cascade constraint;

create table supplier(
	name varchar2(30) not null,
	address varchar2(30) not null,
	logo varchar2(30),
	primary key (name)
);

create table item(
	supplier_name varchar2(30) not null,
	model varchar2(30) not null,
	type varchar2(30) not null,
	price number(10,2) not null,
	primary key (supplier_name,model),
	foreign key(supplier_name) references supplier(name)
		on delete cascade
);

create table orders(
	id number(4),
	orders_date date,
	primary key(id)
);

create table quantity(
	supplier_name varchar2(30) not null,
	item_model varchar2(30) not null,
	orders_id number(4) not null,
	quant number(4) not null,
	primary key (supplier_name,item_model,orders_id),
	foreign key (supplier_name,item_model) references item(supplier_name,model)
		on delete cascade,
	foreign key (orders_id) references orders(id)
		on delete cascade 
);

create table cardof(
	card_num number(10) not null,
	customer_name varchar2(30) not null,
	customer_address varchar2(30) not null,
	e_mail varchar2(30) not null,
	primary key (card_num)
);

create table orderedby(
	orders_id number(4) not null,
	card_num number(10) not null references cardof(card_num)
		on delete cascade,
	card_company varchar2(30) not null,
	card_exp_date date not null,
	primary key (orders_id),
	foreign key (orders_id) references orders(id)
		on delete cascade
);