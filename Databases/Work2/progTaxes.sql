drop table customertaxes;
create table customertaxes(
	customer_name varchar2(30),
	customer_address varchar2(30),
	taxes number(10,2));
DECLARE
cursor money is select customer_name,customer_address,sum(amount) as amount from
		(select customer_name,customer_address,(quant*price) as amount 
			from item,quantity,(select customer_name,customer_address,orders_id
				from cardof,orderedby
				where cardof.card_num=orderedby.card_num) cust
		where model=item_model and cust.orders_id=quantity.orders_id) group by customer_name,customer_address;
my_row money%ROWTYPE;
BEGIN
	open money;
	loop
	fetch money into my_row;
	exit when money%NOTFOUND;
	insert into customertaxes
		values(my_row.customer_name,my_row.customer_address,0.18*my_row.amount);
	end loop;
	close money;
END;