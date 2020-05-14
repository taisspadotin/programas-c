using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace TrabalhoEPO2
{
    class Program
    {
        static void Main(string[] args)
        {
            // ArrayList lista = new ArrayList();
            int n;
            int diaH, mesH, anoH;
            Console.WriteLine("Quantas informações deseja cadastrar?");
            n = int.Parse(Console.ReadLine());
            int op1;
            Hashtable tabela1 = new Hashtable();
            string[] pais = new string[n];
            int[] num = new int[n]; ;//unico
            string[] nome = new string[n];
            float[] salario = new float[n];
            string[] pnome = new string[n];//unico
            int[] diaI = new int[n];
            int[] mesI = new int[n];
            int[] anoI = new int[n];
            int[] diaT = new int[n];
            int[] mesT = new int[n];
            int[] anoT = new int[n];
            int[] tempoest = new int[n]; ;
            float[] valorest = new float[n]; ;
            int[] funcresp = new int[n]; ;//(número  funcional).
            Console.WriteLine("Insira a data atual:");
            diaH = int.Parse(Console.ReadLine());
            Console.WriteLine("mes");
            mesH = int.Parse(Console.ReadLine());
            Console.WriteLine("ano");
            anoH = int.Parse(Console.ReadLine());

            Console.WriteLine("ESCOLHA:");
            do
            {
                Console.WriteLine("1.inserir informações do funcionario\n2.inserir informações do produto\n3.Buscar\n4.Sair\n5.Salvar um e-mail");
                op1 = int.Parse(Console.ReadLine());
                if (op1 == 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        Console.WriteLine("Nome:");
                        nome[i] = Console.ReadLine();
                        Console.WriteLine("Pais:");
                        pais[i] = Console.ReadLine();
                        Console.WriteLine("Numero:");
                        num[i] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Salario:");
                        salario[i] = float.Parse(Console.ReadLine());
                    }
                }
                if (op1 == 2)
                {

                    for (int j = 0; j < n; j++)
                    {
                        Console.WriteLine("Nome:");
                        pnome[j] = Console.ReadLine();
                        Console.WriteLine("Tempo estimado do projeto(em meses):");
                        tempoest[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Valor estimado:");
                        valorest[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("numero do funcionario responsavel:");
                        funcresp[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Dia inicio:");
                        diaI[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("mes inicio:");
                        mesI[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ano inicio:");
                        anoI[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Dia Termino:");
                        diaT[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("mes Termino:");
                        mesT[j] = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ano Termino:");
                        anoT[j] = int.Parse(Console.ReadLine());
                       
                    }

                }
                if (op1 == 3)
                {
                    Console.WriteLine("Escolha o tipo de busca:");
                    Console.WriteLine("1.Busca a partir do número funcional\n2.Ordem decrescente de salário\n3.projetos que  não  estão  terminados e tenham valor estimado  acima  de  R$500.000, 00");
                    Console.WriteLine("4.Ordem alfabetica\n5.Projetos ainda em andamento\n6.Funcionarios responsaveis por projeto");
                    int op2 = int.Parse(Console.ReadLine());
                    if (op2 == 1)
                    {
                        Console.WriteLine("Digite o codigo do funcionario que deseja buscar:");
                        int comp1 = int.Parse(Console.ReadLine());
                        int p, q;
                        for (p = 0; p < n; p++)
                        {
                            if (comp1 == num[p])
                            {
                                int i, j, atual;
                                for (i = 0; i < num.Length; i++)
                                {
                                    atual = num[i];
                                    j = i;
                                    while ((j > 0) && (num[j - 1] > atual))

                                    {
                                        num[j] = num[j - 1];

                                        j = j - 1;

                                    }

                                    num[j] = atual;
                                    Console.WriteLine(nome[j]);
                                    Console.WriteLine(pais[j]);
                                    Console.WriteLine(salario[j]);
                                }




                            }


                            if (comp1 != num[p])
                            {
                                Console.WriteLine("Numero invalido!!");
                            }

                        }

                    }
                    if (op2 == 2)
                    {

                        int min;
                        float aux;
                        for (int i = 0; i < salario.Length - 1; i++)
                        {
                            min = i;
                            for (int j = i + 1; j < salario.Length; j++)
                                if (salario[j] > salario[min])
                                {
                                    min = j;

                                }
                            if (min != i)
                            {
                                aux = salario[min];
                                salario[min] = salario[i];
                                salario[i] = aux;

                            }
                            for (int y = 0; y < n; y++)
                            {
                                Console.WriteLine("Nome:", nome[y]);
                                Console.WriteLine("Numero:", num[y]);
                                Console.WriteLine("País:", pais[y]);
                                Console.WriteLine("Salario:", salario[y]);
                            }
                        }
                    }

                            
                        if(op2 == 3)
                        {
                        for (int k = 0; k < n; k++)
                        {
                            if (anoT[k] > anoH ||mesT[k] > mesH && anoH==anoT[k])
                            { 
                                    if (valorest[k] >= 500000)
                                    {
                                        int b = num.Length;
                                        int gap = b / 2;
                                        int temp;

                                        while (gap > 0)
                                        {
                                            for (int i = 0; i + gap < b; i++)
                                            {
                                                int j = i + gap;
                                                temp = num[j];

                                                while (j - gap >= 0 && temp < num[j - gap])
                                                {
                                                    num[j] = num[j - gap];
                                                    j = j - gap;
                                                }

                                                num[j] = temp;
                                            }

                                            gap = gap / 2;

                                        }
                                        Console.WriteLine("Nome do projeto:", pnome[gap]);
                                        Console.WriteLine("Tempo estimado:", tempoest[gap]);
                                        Console.WriteLine("Valor estimado:", valorest[gap]);
                                    }
                                }
                            }
                        }

                        if(op2 == 4)
                    {
                       for (int t = 0; t < n; t++)
                        {
                            int i, j, atual;
                            for (i = 0; i < num.Length; i++)
                            {
                                atual = num[i];
                                j = i;
                                while ((j > 0) && (num[j - 1] > atual))

                                {
                                    num[j] = num[j - 1];

                                    j = j - 1;

                                }

                                num[j] = atual;
                                char[] chars = nome[t].ToCharArray();
                                Array.Sort(chars);
                                String sorted = new String(chars);
                                Console.WriteLine("Nome:", sorted);
                                Console.WriteLine(pais[j]);
                                Console.WriteLine(num[j]);
                            }




                        }
                                          }
                        if(op2 == 5) {
                        Console.WriteLine("Projetos com atraso:");
                        int i, j, atual;
                        for (i = 0; i < num.Length; i++)
                        {
                            atual = num[i];
                            j = i;
                            int diaHRecebe= diaH*100;
                            int diaTRecebe = diaT[i]*100;
                            if (diaHRecebe+mesH+diaH> diaTRecebe+mesT[i]+diaT[i]) {
                                while ((j > 0) && (num[j - 1] > atual))

                                {
                                    num[j] = num[j - 1];

                                    j = j - 1;

                                }

                                num[j] = atual;
                                Console.WriteLine(pnome[j]);
                                Console.WriteLine(tempoest[j]);
                                Console.WriteLine(num[j]);
                            } }


                    }
                    if (op2 == 6) {
                        //func resp por projetos
                        for (int r = 0; r < n; r++)
                        {
                            for (int d = 0; d < n; d++) {
                                if (num[r] == funcresp[d])
                                {
                                    Console.WriteLine("Nome do funcionario:", nome[r]);
                                    Console.WriteLine("Numero do funcionario:", num[r]);
                                    Console.WriteLine("Nome do projeto:", pnome[d]);
                                }
                        }
                        }
                    }
                }
                if(op1== 5){
                    for (int u = 0; u < n; u++)
                    {
                        Console.WriteLine("Digite o email que deseja inserir:");
                        string email = Console.ReadLine();
                        tabela1[u] = email;
                        Console.WriteLine("Email", tabela1[u]);

                    }

                }

 

                         
                    } while (op1 != 4) ;
                }

            }
}
