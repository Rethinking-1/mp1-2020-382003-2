#pragma once
bool change = false;//����� �� ������
int prioritet = 0;//����� ���������� �� ������������ ���������� ������
std::string temp1;//������ ����� �� �������� ������
std::string temp_dictionary;//������ ����� �� �������(����� ���������� �����������)
size_t pos = 0;//������� ��������� �������� �� ������ ������(���� �� npos)
size_t last_position = 0;//�������  ������ ��������� �����������
size_t mult = 0;//���������� ������ ���������� ������
std::map<std::string, int>::iterator str;//��� �� �������
std::string::iterator it1;//����� �� ��������� ����� �������
std::string::iterator it2;//����� �� ��������� �������� ����� �������� ������