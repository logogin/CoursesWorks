insert into author
	values('Norman Fenton','London');
insert into author
	values('Shari Pfleeger','Boston');
insert into author
	values('William Boyce','Carnegie-Mellon');
insert into author
	values('Richard DiPrima','Carnegie-Mellon');
insert into author
	values('Stanley Farlow','Maine');
insert into author
	values('Morris Mano','Los Angeles');
insert into author
	values('Charles Kime','Madison');
insert into author
	values('Jeffrey Ullman','Stanford');
insert into author
	values('Jennifer Widom','Stanford');
insert into author
	values('Joel Scambray','New York');
insert into author
	values('George Kurtz','Chicago');
insert into author
	values('Henry Edwards','Athens');
insert into author
	values('David Penney','Athens');
insert into author
	values('Richard Stevens','Salt Lake City');
insert into author
	values('Craig Hunt','Washington');
insert into author
	values('Gregory Chaitin','New Mexico');
insert into author
	values('Donald Knuth','Massachusetts');
insert into author
	values('Francis Neelamkavil','Chichester');
insert into author
	values('Gary Wright','Boca-Raton');
/*19 authors*/
insert into publisher
	values('Weisstein','Boston');
insert into publisher
	values('Dover Publications','New York');
insert into publisher
	values('PWS Publishing Company','Boston');
insert into publisher
	values('John Wiley&Sons','New York');
insert into publisher
	values('McGraw-Hill','Berkley');
insert into publisher
	values('Prentice-Hall','London');
insert into publisher
	values('Addison-Wesley','Washington');
insert into publisher
	values('Scientific American','New York');
/*8 publishers*/
insert into store
	values('Collin`s Books','Berkley'); 
insert into store
	values('Best Books','New York');
insert into store
	values('Big Ban','London');
insert into store
	values('1001 Book','Chicago');
insert into store
	values('Best Printings','Boston');
/*5 stores*/
insert into edition
	values(1212,'A First Course in Database Systems','Ullman',2,to_date('1997-12-09','YYYY-DD-MM'));
insert into edition
	values(1313,'Logic and Computer Design Fundamentals','Mano',2,to_date('2001-04-12','YYYY-DD-MM'));
insert into edition
	values(2121,'Hacking Exposed: Network Security Secrets&Solutions','Kurtz',2,to_date('2001-14-02','YYYY-DD-MM'));
insert into edition
	values(3131,'Software Metrics: A Rigorous&Practical Approach','Fenton',2,to_date('1997-17-06','YYYY-DD-MM'));
insert into edition
	values(3232,'Partial Differential Equations','Farlow',1,to_date('1982-30-03','YYYY-DD-MM'));
insert into edition
	values(4545,'Elementary Differential Equations','Boyce',6,to_date('1996-15-11','YYYY-DD-MM'));
insert into edition
	values(2222,'Calculus with Analytic Geometry','Penney',5,to_date('1998-14-07','YYYY-DD-MM'));
insert into edition
	values(3333,'Randomness and Mathematical Proof','Chaitin',1,to_date('1975-14-09','YYYY-DD-MM'));
insert into edition
	values(1111,'The Art of Computer Programming','Knuth',5,to_date('1998-12-05','YYYY-DD-MM'));
insert into edition
	values(3030,'Computer Simulation and Modelling','Wiley',3,to_date('1999-15-08','YYYY-DD-MM'));
insert into edition
	values(5555,'UNIX Network Programming','Stevens',2,to_date('1990-23-02','YYYY-DD-MM'));
insert into edition
	values(1010,'Advanced Programming in the UNIX Envirounment','Stevens',3,to_date('1995-27-10','YYYY-DD-MM'));
insert into edition
	values(4444,'TCP/IP Network Administration','Hunt',4,to_date('1993-17-01','YYYY-DD-MM'));
/*13 editions*/
insert into price
	values(1212,'Collin`s Books','Berkley',34.67);
insert into price
	values(3232,'Collin`s Books','Berkley',190.56);
insert into price
	values(5555,'Collin`s Books','Berkley',345.65);
insert into price
	values(1111,'Collin`s Books','Berkley',27.67);
insert into price
	values(3131,'Collin`s Books','Berkley',46.89);
insert into price
	values(4545,'Collin`s Books','Berkley',789.45);
insert into price
	values(2222,'Collin`s Books','Berkley',345.54);
insert into price
	values(1010,'Best Books','New York',132.89);
insert into price
	values(1212,'Best Books','New York',45.43);
insert into price
	values(2121,'Best Books','New York',67.87);
insert into price
	values(1111,'Best Books','New York',54.23);
insert into price
	values(4545,'Best Books','New York',345.67);
insert into price
	values(2222,'Best Books','New York',98.45);
insert into price
	values(3232,'Best Books','New York',134.67);
insert into price
	values(5555,'Best Books','New York',876.45);
insert into price
	values(1010,'Big Ban','London',456.78);
insert into price
	values(3030,'Big Ban','London',234.65);
insert into price
	values(5555,'Big Ban','London',456.78);
insert into price
	values(3333,'Big Ban','London',35.09);
insert into price
	values(1111,'Big Ban','London',543.12);
insert into price
	values(3232,'Big Ban','London',567.90);
insert into price
	values(4545,'Big Ban','London',98.67);
insert into price
	values(2222,'Big Ban','London',456.43);
insert into price
	values(1212,'Big Ban','London',456.34);
insert into price
	values(4444,'Big Ban','London',256.43);
insert into price
	values(1313,'Big Ban','London',43.45);
insert into price
	values(2121,'Big Ban','London',231.67);
insert into price
	values(3131,'Big Ban','London',90.87);
insert into price
	values(4545,'1001 Book','Chicago',34.76);
insert into price
	values(5555,'1001 Book','Chicago',32.85);
insert into price
	values(1010,'1001 Book','Chicago',90.87);
insert into price
	values(4444,'1001 Book','Chicago',93.87);
insert into price
	values(2121,'1001 Book','Chicago',32.14);
insert into price
	values(3131,'1001 Book','Chicago',49.51);
insert into price
	values(2222,'Best Printings','Boston',876.56);
insert into price
	values(1212,'Best Printings','Boston',465.34);
insert into price
	values(3333,'Best Printings','Boston',876.45);
insert into price
	values(1111,'Best Printings','Boston',235.56);
insert into price
	values(1010,'Best Printings','Boston',345.42);
insert into price
	values(4545,'Best Printings','Boston',876.34);
insert into price
	values(1313,'Best Printings','Boston',986.32);
/*41 prices*/
insert into authorof
	values(3131,'Norman Fenton','London');
insert into authorof
	values(3131,'Shari Pfleeger','Boston');
insert into authorof
	values(4545,'William Boyce','Carnegie-Mellon');
insert into authorof
	values(4545,'Richard DiPrima','Carnegie-Mellon');
insert into authorof
	values(3232,'Stanley Farlow','Maine');
insert into authorof
	values(1313,'Morris Mano','Los Angeles');
insert into authorof
	values(1313,'Charles Kime','Madison');
insert into authorof
	values(1212,'Jeffrey Ullman','Stanford');
insert into authorof
	values(1212,'Jennifer Widom','Stanford');
insert into authorof
	values(2121,'Joel Scambray','New York');
insert into authorof
	values(2121,'George Kurtz','Chicago');
insert into authorof
	values(2222,'Henry Edwards','Athens');
insert into authorof
	values(2222,'David Penney','Athens');
insert into authorof
	values(5555,'Richard Stevens','Salt Lake City');
insert into authorof
	values(1010,'Richard Stevens','Salt Lake City');
insert into authorof
	values(4444,'Craig Hunt','Washington');
insert into authorof
	values(3333,'Gregory Chaitin','New Mexico');
insert into authorof
	values(1111,'Donald Knuth','Massachusetts');
insert into authorof
	values(3030,'Francis Neelamkavil','Chichester');
insert into authorof
	values(1010,'Gary Wright','Boca-Raton');
/*20 authorsof*/
insert into publisherof
	values(1212,'Prentice-Hall','London');
insert into publisherof
	values(1313,'Prentice-Hall','London');
insert into publisherof
	values(2121,'McGraw-Hill','Berkley');
insert into publisherof
	values(3131,'PWS Publishing Company','Boston');
insert into publisherof
	values(3232,'Dover Publications','New York');
insert into publisherof
	values(4545,'John Wiley&Sons','New York');
insert into publisherof
	values(2222,'Prentice-Hall','London');
insert into publisherof
	values(3333,'Scientific American','New York');
insert into publisherof
	values(1111,'Addison-Wesley','Washington');
insert into publisherof
	values(3030,'Weisstein','Boston');
insert into publisherof
	values(5555,'PWS Publishing Company','Boston');
insert into publisherof
	values(1010,'McGraw-Hill','Berkley');
insert into publisherof
	values(4444,'John Wiley&Sons','New York');
/*13 publishersof*/