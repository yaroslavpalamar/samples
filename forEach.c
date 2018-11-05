#include <stdio.h>

#define FOR_EACH(item, list) \
	for (struct list_node *(item)=(list); (item); (item) = (item)->next)

struct list_node {
	struct list_node *next;
	void *data;
};

int 
main(int argc, char**argv) 
{
	struct list_node listChar[] = {
		{.next= &listChar[1], .data="test1"},
		{.next= &listChar[2], .data="test2"},
		{.next= NULL, .data="test3"}
	};

	struct list_node listInt[] = {
                {.next= &listInt[1], .data="100"},
                {.next= &listInt[2], .data="200"},
                {.next= NULL, .data="3000"}
        };

	FOR_EACH(item, listChar) {
		printf("%s ", item->data );
	}
		printf("\n");
	FOR_EACH(item, listInt) {
                printf("%s ", item->data );
                printf("\n");
	}
}

