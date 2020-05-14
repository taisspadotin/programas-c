using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace provaepop2
{
    class Program
    {
        public struct autores
        {
            public int codigo;
            public string nome;
            public int telefone;
            public string email;
            public int qntlivrospu;
            public int qntlivrosre;
            public string areaatuacao;
            public int tipotrab;
        };
        public struct livros
        {
            public int id;
            public string titulo;
            public int diaprev;
            public int mesprev;
            public int anoprev;
            public int codautorprinc;
            public int qntautores;
            public int revprinc;
            public int status;
            public string areaprilivro;
            public float custototal;
        };

        static public string[] hs = new string[200];
        static void posicao_hs(autores a, int n) {

            int pos = 0;
            pos = pos + a.email.Length + a.codigo;
            pos = pos % n;
            if (hs[pos] != "")
            {
                int pos2 = 0;
                pos2 = (a.codigo * a.email.Length) % 4;
                hs[pos2] = a.email;
            }

            else
                hs[pos] = a.email;

            if (hs[pos] != "")
            {
                Console.WriteLine("\nInserido com exito na hash");
                Console.WriteLine(a.email);
            }




        }

        public static void ordena_livro(livros[] l, int n, int compcod)
        {
            int i = 0, j = 0;
            livros aux;

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - 1; j++)
                {
                    if (l[j].id > l[j + 1].id)
                    {
                        aux = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = aux;
                    }
                }
            }

            buscalivro(l, compcod, n);
        }

        public static int buscalivro(livros[] ll, int compcod, int n)
        {
            int inf = 0, sup, meio;
            sup = n - 1;

            while (inf <= sup)
            {
                meio = (inf + sup) / 2;

                if (compcod == ll[meio].id)
                {
                    Console.WriteLine(ll[meio].id);
                    Console.WriteLine(ll[meio].titulo);
                    Console.WriteLine(ll[meio].diaprev);
                    Console.WriteLine(ll[meio].mesprev);
                    Console.WriteLine(ll[meio].anoprev);
                    Console.WriteLine(ll[meio].status);
                    Console.WriteLine(ll[meio].codautorprinc);
                    Console.WriteLine(ll[meio].qntautores);
                    Console.WriteLine(ll[meio].revprinc);
                    Console.WriteLine(ll[meio].areaprilivro);
                    Console.WriteLine(ll[meio].custototal);
                    int op5 = 0;
                    do
                    {
                        Console.WriteLine("O que deseja atualizar?");
                        Console.WriteLine("1.Titulo\n2.Data de publicação\n3.Status\n4.Autor principal\n5.Quantidade de autores\n6.revisor Principal\n7.Area principal\n8.Custo Total\n9.Sair");
                        op5 = int.Parse(Console.ReadLine());
                        if (op5 == 1)
                        {
                            Console.WriteLine("Insira o Titulo:");
                            ll[meio].titulo = Console.ReadLine();
                        }
                        if (op5 == 2)
                        {
                            Console.WriteLine("Insira a Data de publicação:");
                            Console.WriteLine("Dia");
                            ll[meio].diaprev = int.Parse(Console.ReadLine());
                            Console.WriteLine("Mes");
                            ll[meio].mesprev = int.Parse(Console.ReadLine());
                            Console.WriteLine("Ano");
                            ll[meio].anoprev = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 3)
                        {
                            Console.WriteLine("Insira o status");
                            ll[meio].status = int.Parse(Console.ReadLine());

                        }
                        if (op5 == 4)
                        {
                            Console.WriteLine("Insira o codigo autor principal:");
                            ll[meio].codautorprinc = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 5)
                        {
                            Console.WriteLine("Insira a Quantidade de autores:");
                            ll[meio].qntautores = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 6)
                        {
                            Console.WriteLine("Insira o revisor principal:");
                            ll[meio].revprinc = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 7)
                        {
                            Console.WriteLine("Insira a area principal:");
                            ll[meio].areaprilivro = Console.ReadLine();
                        }
                        if (op5 == 8)
                        {
                            Console.WriteLine("Insira o custo Total:");
                            ll[meio].custototal = int.Parse(Console.ReadLine());
                        }
                    } while (op5 != 9);
                    break;
                }
                else
                {
                    if (compcod < ll[meio].id)
                    {
                        sup = meio - 1;
                    }
                    else
                    {
                        inf = meio + 1;
                    }
                }
            }

            return (-1);

        }
        public static void ordenaautor(autores[] aa, int n, int compcod)
        {
            int i = 0, j = 0;
            autores aux;

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - 1; j++)
                {
                    if (aa[j].codigo > aa[j + 1].codigo)
                    {
                        aux = aa[j];
                        aa[j] = aa[j + 1];
                        aa[j + 1] = aux;
                    }
                }
            }

            buscaautores(aa, compcod, n);
        }

        public static void buscaautores(autores[] aa, int compcod, int n)
        {
            int inf = 0, sup, meio;
            sup = n - 1;

            while (inf <= sup)
            {
                meio = (inf + sup) / 2;

                if (compcod == aa[meio].codigo)
                {
                    Console.WriteLine(aa[meio].codigo);
                    Console.WriteLine(aa[meio].nome);
                    Console.WriteLine(aa[meio].telefone);
                    Console.WriteLine(aa[meio].email);
                    Console.WriteLine(aa[meio].qntlivrospu);
                    Console.WriteLine(aa[meio].qntlivrosre);
                    Console.WriteLine(aa[meio].areaatuacao);
                    Console.WriteLine(aa[meio].tipotrab);

                    int op5 = 0;
                    do
                    {
                        Console.WriteLine("O que deseja atualizar?");
                        Console.WriteLine("1.Nome\n2Telefone\n3.Email\n4.Quantidade de livros publicados\n5.Quantidade de livros revisados\n6.Principal Areade atuação\n7.Tipo de trabalho(1.Autor-2.Revisor-3.Ambos)\n8.Sair");
                        op5 = int.Parse(Console.ReadLine());
                        if (op5 == 1)
                        {
                            Console.WriteLine("Insira o Nome:");
                            aa[meio].nome = (Console.ReadLine());
                        }

                        if (op5 == 2)
                        {
                            Console.WriteLine("Insira o telefone");
                            aa[meio].telefone = int.Parse(Console.ReadLine());

                        }
                        if (op5 == 3)
                        {
                            Console.WriteLine("Insira o email:");
                            aa[meio].email = (Console.ReadLine());
                        }
                        if (op5 == 4)
                        {
                            Console.WriteLine("Insira a Quantidade de livros pyublicados:");
                            aa[meio].qntlivrospu = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 5)
                        {
                            Console.WriteLine("Insira a Quantidade de livros revisados:");
                            aa[meio].qntlivrosre = int.Parse(Console.ReadLine());
                        }
                        if (op5 == 6)
                        {
                            Console.WriteLine("Insira a area principal:");
                            aa[meio].areaatuacao = Console.ReadLine();
                        }
                        if (op5 == 7)
                        {
                            Console.WriteLine("Insira o tipo de trabalho:");
                            aa[meio].tipotrab = int.Parse(Console.ReadLine());
                        }
                    } while (op5 != 8);
                    break;
                }
            }
        }
        public static void ordena(livros[] l, int n)
        {
            int i = 0, j = 0;
            livros aux;

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - 1; j++)
                {
                    if (l[j].diaprev > l[j + 1].diaprev)
                    {
                        aux = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = aux;

                    }
                }
            }

            buscadia(l, n);

        }
        public static void buscadia(livros[] l, int n)
        {
            int p;
            bool achou = false;
            for (p = 0; p < n; p++)
            {
                if (l[p].mesprev == 05 && l[p].anoprev == 2017 && l[p].status == 1)
                {
                    achou = true;

                    Console.WriteLine(l[p].id);
                    Console.WriteLine(l[p].titulo);
                    Console.WriteLine(l[p].diaprev);
                    Console.WriteLine(l[p].mesprev);
                    Console.WriteLine(l[p].anoprev);
                    Console.WriteLine(l[p].status);
                    Console.WriteLine(l[p].codautorprinc);
                    Console.WriteLine(l[p].qntautores);
                    Console.WriteLine(l[p].revprinc);
                    Console.WriteLine(l[p].areaprilivro);
                    Console.WriteLine(l[p].custototal);

                }
            }
            if (achou == false)
            {
                Console.WriteLine("Nenhum dado encontrado!");
            }
        }

        public static void ordenanome(int posi, autores[] a, int n)
        {


            int num = a[n].telefone;

            int i = num, j = n;
            while (i < j)
            {
                while (i < j && a[j].telefone > num)
                {
                    j--;
                }

                a[i] = a[j];

                while (i < j && a[i].telefone < num)
                {
                    i++;
                }

                a[j] = a[i];
            }

            a[i].telefone = num;
             //QuickSort(a, start, i - 1);
            //QuickSort(a, i + 1, end);
            a[i].nome.CompareTo(a[j].nome);
            Console.WriteLine(a[j].telefone);
            Console.WriteLine(a[j].nome);
        }


    
        

        static void Main(string[] args)
        {
            int n = 0;
            Console.WriteLine("Tamanho do vetor");
            n = int.Parse(Console.ReadLine());
            autores[] a = new autores[n];
            Hashtable[] emailrev = new Hashtable[n];
            livros[] l = new livros[n];
            int op1 = 0;
            do
            {
                Console.WriteLine("1.Inserir autor\n2.Inserir Livro\n3.Livros em andamento\n4.sair\n5.Atualiza Livro\n6.Atualizar Autor\n7.Adicionar e-mail\n9.Ordem alfabetica");
                op1 = int.Parse(Console.ReadLine());

                if (op1 == 1)
                {
                    Console.Clear();

                    for (int u = 0; u < n; u++)
                    {
                        Console.WriteLine("Codigo:");
                        a[u].codigo = int.Parse(Console.ReadLine());
                        Console.WriteLine("Nome:");
                        a[u].nome = (Console.ReadLine());
                        Console.WriteLine("Telefone:");
                        a[u].telefone = int.Parse(Console.ReadLine());
                        Console.WriteLine("Email:");
                        a[u].email = (Console.ReadLine());
                        Console.WriteLine("Quantidade de livro publicado:");
                        a[u].qntlivrospu = int.Parse(Console.ReadLine());
                        Console.WriteLine("Quantidade de livros revisados:");
                        a[u].qntlivrosre = int.Parse(Console.ReadLine());
                        Console.WriteLine("Area de atuação:");
                        a[u].areaatuacao = (Console.ReadLine());
                        Console.WriteLine("Tipo de trabalho:");
                        a[u].tipotrab =int.Parse(Console.ReadLine());
                    }


                }
                if (op1 == 2)
                {
                    for (int i = 0; i < n; i++)
                    {
                        Console.Clear();

                        Console.WriteLine("Id:");
                        l[i].id = int.Parse(Console.ReadLine());
                        Console.WriteLine("titulo:");
                        l[i].titulo = (Console.ReadLine());
                        Console.WriteLine("Data Prevista:");
                        Console.WriteLine("Dia:");
                        l[i].diaprev = int.Parse(Console.ReadLine());
                        Console.WriteLine("Mes:");
                        l[i].mesprev = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ano:");
                        l[i].anoprev = int.Parse(Console.ReadLine());
                        Console.WriteLine("Codigo do autor principal:");
                        l[i].codautorprinc = int.Parse(Console.ReadLine());
                        Console.WriteLine("Quantidade de autores:");
                        l[i].qntautores = int.Parse(Console.ReadLine());
                        Console.WriteLine("Revisor Principal:");
                        l[i].revprinc = int.Parse(Console.ReadLine());
                        Console.WriteLine("Status");
                        Console.WriteLine("1.em escrita\n2.em Revisão\n3.terminado");
                        l[i].status = int.Parse(Console.ReadLine());
                        Console.WriteLine("Area principal do livro");
                        l[i].areaprilivro = Console.ReadLine();
                        Console.WriteLine("Custo total:");
                        l[i].custototal = float.Parse(Console.ReadLine());
                    }
                }
                if (op1 == 3)
                {
                    ordena(l, n);
                }

                if (op1 == 5)
                {
                    Console.WriteLine("Digite o codigo que deseja buscar");
                    int compcod = int.Parse(Console.ReadLine());

                    ordena_livro(l, n, compcod);


                }

                if (op1 == 6)
                {
                    Console.WriteLine("Digite o codigo que deseja buscar");
                    int compcod = int.Parse(Console.ReadLine());
                    ordenaautor(a, n, compcod);

                }
                if (op1 == 7)
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (a[i].codigo == l[k].codautorprinc)
                            {
                                posicao_hs(a[i], n);
                            }
                        }
                    }
                }
              
                if (op1==9)
                {
                  
for(int g = 0; g < n; g++)
                    {
                        if (a[g].tipotrab == 2)
                        {
                            if(a[g].qntlivrospu>= 02 && a[g].qntlivrosre>= 03)
                            {
                                 int posi = g;
                                ordenanome(posi, a, n);
                            }
                        }
                    }
                }
              }while (op1 != 4) ;
          }
            
    }
}
