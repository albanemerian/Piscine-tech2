int main(void)
{
    int_list_t *list = NULL;
//     unsigned int size = 0;
//     bool temp = true;

    printf("int_list_get_size: %d\n", int_list_get_size(list));
    printf("int_list_is_empty: %d\n", int_list_is_empty(list));
    printf("int_list_del_elem_at_front: %i\n", int_list_del_elem_at_front(&list));
    printf("int_list_add_elem_at_back: %i\n", int_list_del_elem_at_back(&list));
    int_list_add_elem_at_back(&list, 1804289383);
    int_list_add_elem_at_back(&list, 846930886);
    int_list_add_elem_at_back(&list, 1681692777);
    int_list_add_elem_at_back(&list, 1714636915);
    int_list_add_elem_at_back(&list, 1957747793);
    int_list_add_elem_at_back(&list, 424238335);
    int_list_add_elem_at_back(&list, 719885386);
    int_list_add_elem_at_back(&list, 1649760492);
    int_list_add_elem_at_back(&list, 596516649);
    int_list_add_elem_at_back(&list, 1189641421);
    int_list_add_elem_at_back(&list, 1025202362);
    int_list_add_elem_at_back(&list, 1350490027);
    int_list_dump(list);
    printf("int_list_del_elem_at_front: %i\n",int_list_del_elem_at_front(&list));
    printf("int_list_del_elem_at_front: %i\n",int_list_del_elem_at_front(&list));
    printf("int_list_del_elem_at_front: %i\n",int_list_del_elem_at_front(&list));
    int_list_dump(list);;
    printf("int_list_del_elem_at_position: %i\n", int_list_del_elem_at_position(&list, 8));
    printf("int_list_del_elem_at_position: %i\n", int_list_del_elem_at_position(&list, 4));
    printf("int_list_del_elem_at_position: %i\n", int_list_del_elem_at_position(&list, 0));
    int_list_dump(list);
    printf("int_list_del_elem_at_position: %i\n", int_list_del_elem_at_position(&list, 10));
    printf("int_list_del_elem_at_position: %i\n", int_list_del_elem_at_position(&list, 20));
    int_list_dump(list);
    int_list_clear(&list);
}
