drop table notvalidcards;
create table notvalidcards(
cname varchar2(30),
caddress varchar2(30),
card_number number(10),
exp_date date
);
DECLARE
name cardof.customer_name%TYPE;
address cardof.customer_address%TYPE;
num cardof.card_num%TYPE;
edate orderedby.card_exp_date%TYPE;
cursor dates is select customer_name,customer_address,cardof.card_num,card_exp_date from
	cardof,orderedby where cardof.card_num=orderedby.card_num;
BEGIN
	open dates;
	loop
	fetch dates into name,address,num,edate;
	exit when dates%NOTFOUND;
	if edate<to_date('27-05-2003','DD-MM-YYYY') then
	insert into notvalidcards
		values(name,address,num,edate);
	end if;
	end loop;
	close dates;	
END;