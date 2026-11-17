Service service = new();
bool flag = true;
int m = 0;
while (flag)
{
  Console.Write("1.추가 2.번호로검색 3.전화번호수정 4.번호로삭제 5.전체목록 6.종료");
  m = Convert.ToInt32(Console.ReadLine());
  switch (m)
  {
    case 1:
      service.addPerson();
      break;
    case 2:
      service.getPerson();
      break;
    case 3:
      service.updatePerson();
      break;
    case 4:
      service.deletePerson();
      break;
    case 5:
      service.printPersons();
      break;
    case 6:
      flag = false;
      break;
  }
}