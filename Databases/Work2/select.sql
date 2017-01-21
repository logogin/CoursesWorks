/*amount of cars sold by each supplier*/
select name,address,sum as amount 
	from supplier,(select supplier_name,sum(quant) as sum 
				from quantity group by supplier_name) 
	where name=supplier_name;

/*information about order 1111*/
select customer_name,customer_address,card_num,orders_date,item.type,quant
		from cardof,orders,quantity,item
		where ((card_num,orders.id,orders.orders_date) in
		(select orderedby.card_num,orders_id,orders_date 
			from orderedby,orders
			where (orders_id,orders_date) in 
				(select id,orders_date from orders where id='1111')))
		and (quantity.orders_id=orders.id and quantity.item_model=item.model);

/*customers that have bought something*/
select c.customer_name,c.customer_address,o.orders_id
	from cardof c,orderedby o
	where (c.card_num,o.orders_id) in (select card_num,orders_id from orderedby);

/*list of the most prefered cars*/
select distinct type,model,amount
	from item,(select item_model,sum(quant) as amount 
			from quantity group by item_model)
	where amount>=all(select amount 
				from (select distinct type,model,amount 
					from item,(select item_model,sum(quant) as amount 
							from quantity group by item_model)
				where model=item_model)) and model=item_model;

/*list of all suppliers of 'Mercedes' and their prices*/
select name,address,logo,model,price
	from supplier,item
	where (name,model) in (select supplier_name,model 
				from item 
				where type='Mercedes');

/*list of cars that have not sold yet*/
select type,model,price 
	from item
minus
select type,item_model,price
	from item,quantity
	where item.model=quantity.item_model;

/*amount of money spent by each customer*/
select customer_name,customer_address,sum(amount) as amount from
(select customer_name,customer_address,(quant*price) as amount 
	from item,quantity,(select customer_name,customer_address,orders_id
				from cardof,orderedby
				where cardof.card_num=orderedby.card_num) cust
	where model=item_model and cust.orders_id=quantity.orders_id) group by customer_name,customer_address;

/*customers that have bought nothing*/
select customer_name,customer_address,card_num
	from cardof
minus
select customer_name,customer_address,cardof.card_num
	from cardof,orderedby
	where (cardof.card_num,orderedby.orders_id) in 
			(select card_num,orders_id from orderedby);

/*inserts*/
/*add new Opels to the order 1111*/
insert into quantity(supplier_name,item_model,orders_id,quant)
	select supplier_name,model,1111,1
		from (select supplier_name,model 
			from item where type='Opel');

/*add new order for customer Darel Hickman*/
insert into orders
	values(6666,to_date('12-03-2003','DD-MM-YYYY'));

/*add new order to the credit card of Darel Hickman*/
insert into orderedby
	values(6666,5500550055,'VISA',to_date('13-11-2006','DD-MM-YYYY'));

/*add items to the order of customer Darel Hickman*/
insert into quantity(supplier_name,item_model,orders_id,quant)
	select supplier_name,a.model,b.orders_id,1
		from (select supplier_name,model 
			from item 
			where model='Boxter' and type='Porshe') a,
		(select orders_id 
			from cardof,orderedby 
			where customer_name='Darel Hickman' 
				and cardof.card_num=orderedby.card_num) b;

/*deletes*/
delete from supplier
	where name='Colmobile Hyundai';
delete from item
	where type='Hyundai';

/*updates*/
update quantity
	set quant=3
	where item_model='Glooper' and orders_id=2222;
update orderedby
	set card_exp_date=to_date('20-12-2008','DD-MM-YYYY')
	where card_num in
		(select card_num from cardof where customer_name='Darel Hickman');