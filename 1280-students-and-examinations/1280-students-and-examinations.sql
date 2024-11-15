# Write your MySQL query statement below
select s.student_id, s.student_name, sub.subject_name, count(exam.subject_name) as attended_exams
from students as s
join subjects as sub
left join examinations as exam
on s.student_id = exam.student_id and sub.subject_name = exam.subject_name
group by s.student_id, sub.subject_name
order by s.student_id, sub.subject_name;