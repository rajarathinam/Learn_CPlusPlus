TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14


SOURCES += \
    access_private.cpp \
    allareequaltonumber.cpp \
    anagram.cpp \
    array_add_number.cpp \
    avid_tv.cpp \
    BigInt.cpp \
    Binary_Tree_new.cpp \
    binary_tree.cpp \
    bubble_sort.cpp \
    build_binarytree_from_inorderand_preorder_traversals.cpp \
    check_primenumber.cpp \
    checkRotationStringFound.cpp \
    circularpalindromes.cpp \
    clonelinkedlist.cpp \
    contenate_zigzag_string_rows.cpp \
    Convert2anybase.cpp \
    counter_clockwise_print_binary_tree.cpp \
    countofcharactersinstring.cpp \
    decimal2binary.cpp \
    decorator_pattern.cpp \
    doubly_linked_list.cpp \
    eightqueens_C++.cpp \
    eightqueens.cpp \
    factorial.cpp \
    factory_pattern.cpp \
    fibonacii_series.cpp \
    Finaal_Class.cpp \
    functors.cpp \
    gcdoftwonumbers.cpp \
    geek_givencharscanformpalindrome.cpp \
    geek_helloworld_maxchars_occurrence.cpp \
    geek_train_platform_problem.cpp \
    genericstack.cpp \
    graph.cpp \
    helper.cpp \
    hrsminsseconds.cpp \
    infix2postfix.cpp \
    infixexpressionevaluator.cpp \
    insertion_sort.cpp \
    integerarraytointeger.cpp \
    isBST.cpp \
    isomorphicstrings.cpp \
    kla_search.cpp \
    Learn_CPP.cpp \
    linkedlist_cpp.cpp \
    linkedlist_x.cpp \
    linkedlist.cpp \
    longest_increasing_sequence.cpp \
    longestpalindromesubstring.cpp \
    MaxdepthoftheTree.cpp \
    mode_frquency_of_numbers_in_array.cpp \
    morris_inorder_traversal.cpp \
    myatoi.cpp \
    myFunc.cpp \
    mymemmove.cpp \
    mymutex.cpp \
    myprintf.cpp \
    mystrcat.cpp \
    mystrstr.cpp \
    mytoupper.cpp \
    newAndDelete.cpp \
    nth_Fibonacci_number.cpp \
    numberofbitsrequired.cpp \
    OnlyHeap.cpp \
    palindrome.cpp \
    palindromecheckwithstartandend.cpp \
    parenthesis_permutation.cpp \
    Pattern_match_index.cpp \
    perfectsingleton.cpp \
    permutation_of_a_string.cpp \
    postfixexpressionevaluator.cpp \
    pragma.cpp \
    print_all_possible_combinations_of_parenthesis_for_n.cpp \
    print_matrix_elements_helically.cpp \
    pure_virtual_function.cpp \
    Pythogorean_triples.cpp \
    QueueUsing2Stack.cpp \
    queuewithvector_implementation.cpp \
    quick_select_algorithm_tofind_kthsmallest_element.cpp \
    quick_sort.cpp \
    ranges_dont_overlap.cpp \
    ratandmaze.cpp \
    Remove_string2_chars_from_string1.cpp \
    removeDupFromString.cpp \
    reversing_bits_of_an_integer.cpp \
    reversing_words_of_a_sentence.cpp \
    row_with_max_zeros_in_a_matrix.cpp \
    running_time.cpp \
    seggregate0s1s2s.cpp \
    selection_sort.cpp \
    settingbits.cpp \
    shared_ptr_circularreference.cpp \
    singleton_4_versions.cpp \
    singleton_call_once.cpp \
    sizeofarray.cpp \
    sort0s1s2s_array.cpp \
    sorting_array_contains_0s_and_1s.cpp \
    stackusinglinkedlist.cpp \
    sting_difference.cpp \
    string_prefix_suffix_extract.cpp \
    string.cpp \
    stringbuilder.cpp \
    stringreverse.cpp \
    stringsofnbits.cpp \
    swapnthnodes.cpp \
    symbol_balanced_checker.cpp \
    taskdialog.cpp \
    three_Stacks_in_single_Array.cpp \
    Tower_of_Hanoi.cpp \
    stack_with_order_1_pop_push_min.cpp \
    Amazon_find_unique_chars_from_two_strings.cpp \
    Amazon_Paranthesis_Match_Check.cpp \
    Split_String_divisible_by_and_b.cpp \
    stack_with_2_queues.cpp \
    Amazon_Maximize_0s_in_Array_by_one_flip.cpp \
    Amazon_Trie.cpp \
    Amazon_Anagram_check.cpp \
    stackarray.cpp \
    pimplpattern.cpp \
    book.cpp \
    kthlargestnumber.cpp \
    splitmatrix.cpp \
    oddeventhread.cpp \
    singletoncallonce.cpp \
    future_promise_async.cpp \
    memory_leak_detection.cpp \
    memory_leak_detection_test.cpp \
    print_matrix_diagonally.cpp \
    rotate_array_n_times.cpp \
    count_distinctpairs_sumtok.cpp \
    semphore_implementation.cpp \
    lrucache.cpp \
    crash_on_exceptionthrownfromdestructor.cpp \
    memorypooldesign.cpp \
    datarace_racecondition.cpp \
    longestcommonsubsquence.cpp \
    firstnonrepeatablecharacter.cpp \
    telephonenumbers_to_wordcombinations.cpp \
    smartptr.cpp \
    pairsofsumanddifferences.cpp \
    excelcolumnnametonumber.cpp \
    observerpattern.cpp \
    binarytree_4dec2019.cpp \
    find_longest_unique_substring.cpp \
    issameclass_template.cpp
QMAKE_CXXFLAGS += -std=c++11
include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    LastNLinesFileReading.zip

HEADERS += \
    BigInt.h \
    Job.h \
    linkedlist.h \
    print_binary_tree.h \
    stringbuilder.h \
    stub.h \
    taskdialog.h \
    book.h \
    memory_leak_detector.h \
    template_declaration.h


#INCLUDEPATH += ../Learn_CPP/3rdParty/boost_1_69_0/include/
#DEPENDPATH += ../Learn_CPP/3rdParty/boost_1_69_0/include/
