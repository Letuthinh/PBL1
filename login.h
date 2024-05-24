#pragma once
#include<iostream>//thu vien chuan c++
#include<istream>//dung de su dung ham getline cho string
#include<fstream> // thu vien voi cac ham dung de doc,xuat file
#include<sstream> /* bien xau string tu du lieu dau vao thanh mot luong (tuong tu nhu nhap tu ban phim) ket hop voi do la tach du lieu tu 
                    thanh tung phan rieng biet de tiep tuc xu li nhung cong viec tiep theo*/
#include<string.h> // thu vien string cua C#
#include <windows.h> // để thiết lập màu chữ, định dạng nội dung cho hệ thống

using namespace std;
int admin(); // ham dung de dang nhap vao menu "quan li nhan vien" (chi duy nhat 1 tai khoan voi tendangnhap va matkhau mac dinh)
int user(); // ham dung de dang nhap vao menu "quan li kho" (phai dang ky truoc khi dang nhap)
void dangky(); /* ham dung de dang ki moi tai khoan (ngoai tendangnhap va matkhau con yeu cau 
them cac thong tin co ban dung de quan li nhan vien)  */
void quen();/*tim lai tai khoan thong qua tim lai tennguoidung hoac matkhau*/
void SET_MAU(int MAU);/*dung de dinh dang lai mau phong chu cua man hinh console*/

