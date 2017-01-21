/*views*/
/*information about all orders*/
drop view allorders;
create view allorders as
select id,customer_name,customer_address,card_num,orders_date,item.type,quant
		from cardof,orders,quantity,item
		where ((card_num,orders.id,orders.orders_date) in
		(select orderedby.card_num,orders_id,orders_date 
			from orderedby,orders
			where (orders_id,orders_date) in 
				(select id,orders_date from orders)))
		and (quantity.orders_id=orders.id and quantity.item_model=item.model);
select * from allorders;

/*all saled cars*/
drop view allcars;
create view allcars as
select type,model,amount
	from item,(select item_model,sum(quant) as amount 
			from quantity group by item_model)
	where model=item_model;
select * from allcars order by type;

/*information about all customers that have bought something and their cred cards*/
drop view allcustomers;
create view allcustomers as
select customer_name,customer_address,e_mail,cardof.card_num,card_company,card_exp_date
	from cardof,orderedby
	where cardof.card_num=orderedby.card_num;
select * from allcustomers order by customer_name;