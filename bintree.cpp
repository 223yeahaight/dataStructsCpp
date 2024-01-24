#include <iostream>

using namespace std;

int maks(int a, int b)
{
    if(a < b)
    {
        return b;
    }
    else if(b < a)
    {
        return a;
    }
    else
    {
        return a;
    }

}

struct element
{
    int data;
    element* left = 0;
    element* right = 0;
};


void add_element(element* nowy, element* root)
{
    if(nowy -> data < root -> data)
    {
        if(root -> left == 0)
        {
            root -> left = nowy;
        }
        else
        {
            add_element(nowy, root -> left);
        }
    }
    else
    {
        if(root -> right == 0)
        {
            root -> right = nowy;
        }
        else
        {
            add_element(nowy, root -> right);
        }
    }
}

bool find_element(int data, element* root)
{
    if (root -> data == data)
    {
        return true;
    }
    else if (data < root -> data)
    {
        if (root->left == 0)
        {
            return false;
        }
        else
        {
            return find_element(data, root->left);
        }

    }
    else
    {
        if (root->right == 0)
        {
            return false;
        }
        else
        {
            return find_element(data, root->right);
        }

    }
}

struct tree
{
    element* root = 0;


    void add(int data)
    {
        element* nowy = new element;
        nowy -> data = data;

        if(root == 0)
        {
            root = nowy;
        }
        else
        {
            add_element(nowy, root);
        }
    }

    bool has_element(int data)
    {
        if (root == 0)
        {
             return false;
        }
        else
        {
            return find_element(data, root);
        }
    }

    int depth(element* root)
    {
        if(root == 0)
        {
            return 0;
        }
        else
        {
            return maks(depth(root -> left), depth(root -> right)) + 1;
        }
    }

    element* second_last_to_right(element* root)
    {
        if(root -> right -> right == 0 || root -> right == 0)
        {
            return root;
        }
        else
        {
            second_last_to_right(root -> right);
        }
    }


    element* second_last_to_left(element* root)
    {
        if(root -> left -> left == 0 || root -> left == 0)
        {
            return root;
        }
        else
        {
            second_last_to_left(root -> left);
        }
    }












    void delete_element(int data, element* root)
        {
            if (root ->  data == data)
            {

                if(root -> right == 0 && root -> left == 0)
                {

                }
                else if(root -> left == 0)
                {

                    root -> data = second_last_to_left(root -> right) -> left -> data;



                    if (second_last_to_left(root -> right) -> left -> right != 0)
                    {
                        second_last_to_left(root -> right) -> left =  second_last_to_left(root -> right) -> left -> right;
                    }
                    else
                    {
                        second_last_to_left(root -> right) -> left = 0;
                    }



                }
                else
                {
                    root -> data = second_last_to_right(root -> left) -> right -> data;



                    if (second_last_to_right(root -> left) -> right -> left != 0)
                    {
                        second_last_to_right(root -> left) -> right =  second_last_to_right(root -> left) -> right -> left;
                    }
                    else
                    {
                        second_last_to_right(root -> left) -> right = 0;
                    }
                }

            }
            else if (data < root -> data)
            {
                delete_element(data, root -> left);
            }
            else
            {
                delete_element(data, root -> right);
            }
    }

    void tree_clear(element* root)
    {
        if (root != 0)
        {
            tree_clear(root->left);
            tree_clear(root->right);
            delete root;
        }

    }

    ~tree()
    {
        cout<<"wykonanie destruktora"<<endl;
        this -> tree_clear(root);
    }




};






    int main()
    {
        tree drzewo;
        drzewo.add(7);
        drzewo.add(20);
        drzewo.add(13);
        drzewo.add(11);
        drzewo.add(12);
        drzewo.add(15);
        drzewo.add(14);
        drzewo.add(17);
        drzewo.add(16);
        drzewo.add(21);
        drzewo.add(22);

        drzewo.delete_element(20, drzewo.root);
        cout<<drzewo.has_element(20);
        cout<<drzewo.has_element(13);





    }


