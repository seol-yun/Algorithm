SELECT MONTH(start_date) as MONTH, CAR_ID, count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in 
(
 select car_id
 from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
 where start_date>='2022/08/00' and start_date<='2022/10/31'
 group by car_id
 having count(car_id)>=5
)
and start_date>='2022/08/00' and start_date<='2022/10/31'
group by car_id, month
having records>0
order by month asc, car_id desc;
