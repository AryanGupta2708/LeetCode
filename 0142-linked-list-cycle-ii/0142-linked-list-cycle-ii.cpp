class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL)
            return NULL;
        ListNode*s=head,*f=head;
        bool ok=false;
        while(f!=NULL and f->next!=NULL and f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
            if(f==s)
            {
                s=head;
                while(s!=f)
                {
                    s=s->next;
                    f=f->next;
                }
                return s;
            }
        }
        return NULL;
    }
};