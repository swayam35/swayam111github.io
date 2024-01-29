\\ljmca
assignment\TEMP
BRANCH_NAME                   ASSETS BRANCH_CITY
------------------------- ---------- -------------------------
vastrapur                     300000 ahmedabad
kalupur                        30000 ahmedabad
jamalpur                      450000 ahmedabad
sarkhej                       450000 ahmedabad
katargam                      550000 surat
    ACC_NO    BALANCE BRANCH_NAME
---------- ---------- -------------------------
       101       3000 sarkhej
       105       3000 kalupur
       102       4500 sarkhej
       103        450 vastrapur
       104        550 katargam

BRANCH_NAME                   ASSETS BRANCH_CITY  ACC_NO    BALANCE BRANCH_NAME
vastrapur                     300000 ahmedabad 101       3000 sarkhej
vastrapur                     300000 ahmedabad 105       3000 kalupur
vastrapur                     300000 ahmedabad 102       4500 sarkhej
vastrapur                     300000 ahmedabad  103        450 vastrapur
vastrapur                     300000 ahmedabad  104        550 katargam

 select acc_no, balance, branch_city, branch.branch_name, account.branch_name
    from branch,account
    where branch.branch_name = account.branch_name;









SQL Constraints

--table level constraint
CREATE TABLE Branch (
	Branch_name varchar(25),
	Assets int, 
	Branch_city varchar(25) NOT NULL,
	CONSTRAINT BranchPK PRIMARY KEY (Branch_name)
);

CREATE TABLE Account (
	Acc_no int,
	Balance int NOT NULL, 
	Branch_name varchar(25) REFERENCES Branch(Branch_name),
	CONSTRAINT AccountPK PRIMARY KEY (Acc_no)
); 

CREATE TABLE Customer(
	Customer_name  varchar(25),
	Customer_street  varchar(25) NOT NULL,
	Customer_city varchar(25),
	CONSTRAINT CustomerPK PRIMARY KEY (Customer_name)
);

CREATE TABLE Depositor (
	Acc_no int REFERENCES Account(Acc_no),
    Customer_name  varchar(25) REFERENCES Customer(Customer_name) 
);
CREATE TABLE Loan ( 
	Loan_no int, 
	Amount int NOT NULL,
	Branch_name varchar(25) REFERENCES Branch(Branch_name),
	CONSTRAINT LoanPK PRIMARY KEY(Loan_no) 
);

CREATE TABLE Borrower (
	Loan_no int REFERENCES Loan(Loan_no) ,
	Customer_name  varchar(25) REFERENCES Customer(Customer_name) 
);

--insert records Branch table
insert into Branch (Branch_name, Assets, Branch_city) 
values ('vastrapur', 300000, 'ahmedabad');
insert into Branch (Branch_name, Assets, Branch_city) 
values ('kalupur', 30000, 'ahmedabad');
insert into Branch (Branch_name, Assets, Branch_city) 
values ('jamalpur', 450000, 'ahmedabad');
insert into Branch (Branch_name, Assets, Branch_city) 
values ('sarkhej', 450000, 'ahmedabad');
insert into Branch (Branch_name, Assets, Branch_city) 
values ('katargam', 550000, 'surat');
select * from Branch;

--insert records Account table
insert into Account (Acc_no, Balance, Branch_name) 
values (101, 3000, 'sarkhej');
insert into Account (Acc_no, Balance, Branch_name) 
values (105, 3000, 'kalupur');
insert into Account (Acc_no, Balance, Branch_name) 
values (102, 4500, 'sarkhej');
insert into Account (Acc_no, Balance, Branch_name) 
values (103, 450, 'vastrapur');
insert into Account (Acc_no, Balance, Branch_name) 
values (104, 550, 'katargam');
select * from Account;


--insert records Customer table
insert into Customer (Customer_name, Customer_street, Customer_city) 
values ('Alekh', 'l j campus', 'ahmedabad');
insert into Customer (Customer_name, Customer_street, Customer_city) 
values ('Abbas', 'ratan pol', 'ahmedabad');
insert into Customer (Customer_name, Customer_street, Customer_city) 
values ('Rina', 'panjra pol', 'ahmedabad');
insert into Customer (Customer_name, Customer_street, Customer_city) 
values ('Sangeeta', 'satellite', 'ahmedabad');
insert into Customer (Customer_name, Customer_street, Customer_city) 
values ('Tushar', 'ratan pol', 'ahmedabad');
select * from Customer;



--insert records Depositor table
insert into Depositor (Acc_no, Customer_name) 
values (101, 'Alekh');
insert into Depositor (Acc_no, Customer_name) 
values (102, 'Rina');
insert into Depositor (Acc_no, Customer_name) 
values (103, 'Tushar');
select * from Depositor;




--insert records Loan table
insert into Loan (Loan_no, Amount, Branch_name) 
values (301, 2100, 'ratan pol');
insert into Loan (Loan_no, Amount, Branch_name) 
values (302, 3100, 'sarkhej');
insert into Loan (Loan_no, Amount, Branch_name) 
values (303, 4100, 'sarkhej');
insert into Loan (Loan_no, Amount, Branch_name) 
values (304, 1100, 'katargam');
select * from Loan;

--insert records Borrower table
insert into Borrower (Loan_no, Customer_name) 
values (301, 'Tushar');
insert into Borrower (Loan_no, Customer_name) 
values (302, 'Rina');
insert into Borrower (Loan_no, Customer_name) 
values (303, 'Alekh');
insert into Borrower (Loan_no, Customer_name) 
values (304, 'Abbas');
select * from Borrower;



1. Find all branch name having assets more than 1 lac.
2. Find branch names with asset greater than 1 lac but not 
more than 4 lacs.
3. Find branches located in ahmedabad city.
4. Find branches situated in surat or baroda cities.
5.Find names of the branches that starts with character 's'.
6.Find names of the branches that starts with character 's' 
and ends with character 't'.
7. Find all accounts having balance less than or equal to 
10000.
8. Find account details where branch name is sarkhej and
 balance is 10000.
8A. Find account details where branch name is NOT
 sarkhej and balance is 10000.
9. find name of customer living in vastrapur.
10. Find all customer having 'pol' word in their street name.
11. Find all loans which are issued from sarkhej branch and 
amount is more than 30000.
12. List account balance of all accounts after adding 
100 rs in them.
13. Diplay account details after adding 10% interest in 
the account balance.
14. f‌ind account details which are located in ahmedabad city. 





 select branch_name
 from branch
where assets>100000;

select *
from branch
where assets>100000 AND Assets<400000;

select * 
FROM Branch
where Branch_city='ahmedabad'
    OR Branch_city='SURAT'
    OR Branch_city='BARODA';

select * 
FROM Branch
where Branch_city IN('ahmedabad','surat','BARODA');

select * from branch
where Branch_city like 's%';

select * from branch
where Branch_city like 's%t';



1.ADD gender column in customer table.
2. gender values must be male, female or other.
3. add constraint in branch table to check that 
the assets is more or equal to 30000.
4. add column dob in customer table to save birth 
date. (format for date - '01-jan-2001).
5. Insert new records in customer and branch tables.
6.Find names of customers whose birthday falls in january month from 2001  to  2010.

select customer_name
from customer_svp
where to_char(dateofbirth,'YY') BETWEEN 01 AND 10
AND
to_char(dateofbirth,'MM') = 01;









SELECT CUSTOMER_NAME FROM CUSTOMER_SVP
WHERE to_char(dateofbirth,'YY') BETWEEN 01 AND 24
AND to_char(dateofbirth,'MM') = 04; 

7.Find names of customers whose birthday falls between january and march.
8.Find details of accounts opened between 2020 to 2023.
9. update balance of account to 0  whose account balance is LESS than 5000.
10. update assets value to 5 lacs where branch name has 'pur' or 'ro' in the name.
11. update loan amount value after deducting 5% of loan amount.(installment).
12. increase account balance by 5%. (Add interest)


1. Find all the details of the bank branches.
2. Find the name of all customers having bank account.
3. Find each loan number along with amount.
4. Find all account number and balance adding 6% yearly interest.
5. Find all account number where balance is less than 3000.
6. Find branch name which is situated in ahmedabad and having assets less than 450000.
7. Find branch name and account number where balance is greater than 400 and less than 4000.
7A. Find branch name and account number where balance is NOT greater than 400 and less than 4000.
8. Find all the loan numbers along with loan amount if the loan is from branch situated in ahmedabad.
-- SET OPERATORS
9. FIND ALL CUSTOMER NAME HAVING AN ACCOUNT OR LOAN OR BOTH.
10. FIND ALL CUSTOMER NAME HAVING AN ACCOUNT AND LOAN.
11.  FIND ALL CUSTOMERS HAVING AN ACCOUNT BUT NOT LOAN.
12. FIND THE NAME OF CUSTOMERS HAVING ACCOUNT IN vastrapur BRANCH.
14.FIND CUSTOMERS WHO HAVE LOAN FROM BRANCH WITH ASSETS LESS THAN 4000000.
15. Find customer name, account number and balance of customers who have accounts located in the cities having 'od' or 'ahm' in the name.
16. Find customer name, city, loan number and loan amount of customers who have
taken loan from a branch having branch name with third character as 'o' and total length of 5 characters.








