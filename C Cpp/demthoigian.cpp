#include <stdio.h>
#include <sys/time.h>
/*
Chương trình đếm thời gian từ khi bắt đầu đến khi ngưng chạy, theo s, ms, us (mico giây, phàn triệu giây)
sử dụng để so sánh thời gian chạy thuật toán hoặc mục đích khác
Tác giả: Nguyễn Thành Nam
Ngày tạo (yy/mm/dd): 23/02/22 

*/
int main () {
	timeval t_begin, t_end; // thoi diem bat dau và ket thuc

	gettimeofday(&t_begin, NULL); // lay gia tri thoi diem bat dau

	printf("Dang dem thoi gian. Nhan enter de ket thuc.");
	getchar();

	gettimeofday(&t_end, NULL);    // lay gia tri thoi diem ket thuc

	// chenh lech thoi gian theo micro giay (10^6 µs= 1 s)
	// gom .tv_sec : giá tri theo giay ; .tv_usec: giá tri theo micro giay (khong bao gom giay)
	long t_us = (t_end.tv_sec * 1000000 + t_end.tv_usec ) - (t_begin.tv_sec * 1000000 + t_begin.tv_usec);
	printf("Thoi gian chay chuong trinh: %lus%3lums%3lu%cs  \n", t_end.tv_sec - t_begin.tv_sec, t_us % 1000000 / 1000, t_us % 1000, 230); // 230= ky tu µ

	return 0;
}
