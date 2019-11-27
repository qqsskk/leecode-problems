#include"stdafx.h"

/*C++�����㷨��STL�����㷨�����򡢺ϲ��������ͷ�����*/
/*
1��C++ sort��STL sort�������㷨

2��C++ stable_sort(STL stable_sort)�����㷨

3��C++ partial_sort(STL partial_sort)�����㷨
������һ���������������� 100 �����ֵ��������ֻ��������С�� 100 ������Ȥ�����Զ�������ȫ����������Ȼ��ѡ��ǰ 100 ��Ԫ�أ���������е�����ʱ�䡣��ʱ����Ҫʹ�ò�������ֻ��Ҫ��Щ���е�ǰ100����������õġ�

4��C++ nth_element(STL nth_element)�����㷨
nth_element() �㷨�� partial_sort() ��ͬ��Ӧ�õķ�Χ�����ĵ�һ���͵���������ָ�����ڶ���������һ��ָ��� n ��Ԫ�صĵ���������������Χ�ڵ�Ԫ������ȫ����ģ�nth_dement() ��ִ�лᵼ�µ� n ��Ԫ�ر��������ʵ���λ�á������Χ�ڣ��ڵ� n ��Ԫ��֮ǰ��Ԫ�ض�С�ڵ� n ��Ԫ�أ������������ÿ��Ԫ�ض���������㷨Ĭ���� < �������������������

5��C++ is_sorted(STL is_sorted)�����㷨
*/

/*
6��C++ merge��inplace_merge��STL merge��inplace_merge���㷨

std::vector<int> these {2, 15, 4, 11, 6r 7};//1st input to merge
std::vector<int> those {5, 2, 3, 2, 14, 11, 6}; // 2nd input to merge
std::stable_sort(std:rbegin(these), std::end(these),std::greatero ());// Sort 1st range in descending sequence
std::stable_sort(std::begin(those), std::end(those), std::greater<>()); // Sort 2nd range
std::vector<int> result(these.size() + those.size() + 10);//Plenty of room for results
auto end_iter = std::merge(std::begin(these), std::end(these),std::begin(those), std::end(those),std::begin (result), std::greater<>());// Merge 1st range and 2nd range into result
std:: copy (std::begin (result), end_iter, std::ostream_iterator<int>{std::cout, " "});
*/

/*
7��C++ find��STL find�������㷨

8��C++ find_if��STL find_if�������㷨

int value {5};
auto iter1 = std::find_if(std::begin(numbers), std::end(numbers),[value](int n) { return n > value; });
if(iter1 != std::end(numbers))
std::cout << *iter1 << " was found greater than " << value << ".\n";

9��C++ find_if_not��STL find_if_not�������㷨

10��C++ find_first_of(STL find_first_of)�����㷨

11��C++ adjacent_find(STL adjacent_find)�㷨ʹ��
adjacent_find() �㷨����������������������������ȵ�Ԫ�ء��� == ��������Ƚ�������һ��Ԫ�أ����صĵ�����ָ��ǰ�������Ԫ���еĵ�һ�������û��һ����ȵ�Ԫ�أ�����㷨����������еĽ�����������

12��C++ find_end(STL find_end)

13��C++ search(STL search)
�ڲ������е������з��棬search() �㷨�� find_end() �㷨���ƣ����������ҵ��ǵ�һ��ƥ������������һ��

14��C++ search_n��STL search_n�������㷨
*/

/*
15��C++ partition(STL partition)�㷨
�������з���Ԫ�ػ����¶�Ԫ�ؽ������У�����ʹ����ν�ʷ��� true ��Ԫ�ػᱻ��������ʹν�ʷ��� false ��Ԫ�ص�ǰ�档����� partition() �㷨�������¡�

partition ��ǰ���������Ƕ��屻�������з�Χ�������������������������һ��ν�ʡ�����չʾ���ʹ�� partition() ���������������е�ֵ������С��ƽ��ֵ��Ԫ�ػᱻ�������д���ƽ��ֵ��Ԫ�صĺ��棺

std::vector<double> temperatures {65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50};
std::copy(std::begin(temperatures), std::end(temperatures), //List the values
std::ostream_iterator<double>{std::cout, " "});
std::cout << std::endl;
auto average = std::accumulate(std::begin(temperatures),std::end(temperatures), 0.0)/temperatures.size();
std::cout << "Average temperature: "<< average << std::endl;
std::partition(std::begin(temperatures), std::end(temperatures),[average](double t) { return t < average; });
std::copy(std::begin(temperatures), std::end(temperatures),std::ostream_iterator<doiible>{std::cout, " "});
std::cout << std::endl;

��δ�������������Щ���ݣ�
65 75 56 48 31 28 32 29 40 41 44 50
Average temperature: 44.9167
44 41 40 29 31 28 32 48 56 75 65 50

16��C++ partition_copy(STL partition_copy)

17��C++ partition_point(STL partition_point)�㷨
*/

/*
18��C++ binary_search(STL binary_search)���ֲ���
19��C++ lower_bound(STL lower_bound)���ֲ���
20��C++ upper_bound(STL upper_bound)���ֲ���
21��C++ equel_range(STL equal_range)���ֲ���
22��C++(STL) all_of��any_of��none_of
*/

/*
23��C++ equal(STL equal)�Ƚ��㷨
24��C++ mismatch(STL mismatch)
*/

/*
25��C++��STL�� lexicographical_compare�ַ��������㷨

�����ַ�������ĸ������ͨ���ӵ�һ���ַ���ʼ�Ƚ϶�Ӧ�ַ��õ��ġ���һ�Բ�ͬ�Ķ�Ӧ�ַ��������ĸ��ַ���������λ���ַ�����˳����ǲ�ͬ�ַ���˳������ַ����ĳ�����ͬ���������е��ַ�����ȣ���ô��Щ�ַ�������ȡ�����ַ����ĳ��Ȳ�ͬ�����ַ������ַ����кͳ��ַ����ĳ�ʼ��������ͬ�ģ���ô���ַ���С�ڳ��ַ�������� ��age�� �ڡ�beauty�� ֮ǰ����a lull�� �� ��a storm�� ֮ǰ����Ȼ����the chicken�� ������ ��the egg�� ��������λ��

�����κ����͵Ķ���������˵���ֵ�������ĸ����˼��ķ��������������еĵ�һ��Ԫ�ؿ�ʼ���αȽ϶�Ӧ��Ԫ�أ�ǰ��������Ĳ�ͬ��������е�˳����Ȼ�������еĶ�������ǿɱȽϵġ�

lexicographical_compare()�㷨���ԱȽ��ɿ�ʼ�ͽ���������������������С�����ǰ�������������˵�һ�����У��� 3 �͵� 4 �������ֱ��ǵڶ������еĿ�ʼ�ͽ�����������Ĭ���� < ��������Ƚ�Ԫ�أ�������Ҫʱ��Ҳ�����ṩһ��ʵ��С�ڱȽϵĺ���������Ϊ��ѡ�ĵ� 5 �������������һ�����е��ֵ���С�ڵڶ���������㷨�᷵�� true�����򷵻� false�����ԣ����� false ������һ�����д��ڻ���ڵڶ������С�

���������Ԫ�رȽϵġ���һ�Բ�ͬ�Ķ�ӦԪ�ؾ��������е�˳��������еĳ��Ȳ�ͬ�����Ҷ����кͳ����еĳ�ʼԪ������ƥ�䣬��ô������С�ڳ����С�������ͬ���Ҷ�ӦԪ�ض���ȵ�������������ȵġ�����������С�ڷǿ����С�������һ��ʹ�� lexicographical_compare() ��ʾ����
std::vector<string> phrase1 {"the", "tigers", "of", "wrath"};
std::vector<string> phrase2 {"the", "horses", "of", "instruction"};
auto less = std::lexicographical_compare (std::begin (phrase1), std: :end (phrase1),
std::begin(phrase2), std::end(phrase2)); std::copy(std::begin(phrase1), std::end(phrase1), std::ostream_iterator<string>{std::cout, " "});
std::cout << (less ? "are":"are not") << " less than ";
std::copy(std::begin(phrase2), std::end(phrase2), std::ostream_iterator <string>{std::cout, " "});
std::cout << std::endl;
��Ϊ��Щ���еĵڶ���Ԫ�ز�ͬ�����ҡ�tigers�����ڡ�horses������δ������������ �����
the tigers of wrath are not less than the horses of instruction

26��C++ next_permutation(STL next_permutation)�㷨
27��C++ prev_permutation(STL prev_permutation)�㷨
28��C++ is_permutation��STL is_permutation���㷨
*/

/*
C++ copy_n(STL copy_n)�㷨
C++ copy_if(STL copy_if)�㷨
C++ copy_backward(STL copy_backward)
C++ reverse_copy(STL reverse_copy)
*/

/*
C++ unique(STL unique)�㷨
unique() �㷨������������ԭ���Ƴ��ظ���Ԫ�أ����Ҫ�󱻴�������б����������������ָ���ġ����Ƴ��ظ�Ԫ�غ����᷵��һ�������������Ϊ�����еĽ�����������
*/

/*
C++ replace,replace_if��replace_copy����
replace() �㷨�����µ�ֵ���滻�͸���ֵ��ƥ���Ԫ�ء�����ǰ���������Ǳ��������е�������������� 3 �������Ǳ��滻��ֵ���� 4 ���������µ�ֵ������չʾ�������÷�:
std::deque<int> data {10, -5, 12, -6, 10, 8, -7, 10, 11};
std::replace(std::begin(data), std::end(data), 10, 99);
// Result: 99 -5 12 -6 99 8 -7 99 11
*/