using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//ARRUMAR A BATALHA
//E ZERAR AS ... 
namespace EPOT_nivel1
{
    public class caminho2//Segunda fase
    {
        //CRIAR O NIVEL 2
        //ZERAR A MOCHILA E CINTO
    }
    //CRIANDO UMA PILHA:
    public class mochila
    {
        public int arma;
        public int pocao;

        public mochila(int armaH, int pocaoH)
        {
            arma = armaH;
            pocao = pocaoH;//FAZENDO A VARIAVEL GLOBAL RECEBER A VARIAVEL DO PROGRAMA
        }
    }
    //CRIANDO UMA LISTA:
    public class cinto
    {
        public int armac;
        public int pocaoc;

        public cinto(int aci, int pci)
        {
            armac = aci;
            pocaoc = pci;
        }

    }
    public class Program
    {
        public static Stack<mochila> mc = new Stack<mochila>();//criando uma pilha
        public static Queue<cinto> ct = new Queue<cinto>();//criando uma lista


        //CRIAR PRA ELE VER  O QUE TA NO CINTO O TEMPO TODO
        static void Main(string[] args)
        {

            int ac;
            int pc;
            mochila novo;
            cinto novoc;
            Console.WriteLine("Digite o nome de seu personagem:");
            string nomedopersonagem = Console.ReadLine();
            int n = 5;//vetor de 5 posições para a vida
            Console.Write("Ola " + nomedopersonagem);
            Console.WriteLine(",o jogo tem dois niveis, a vida, as armas e as poções possuem cinco pontos para\naumentar suas habilidades voce pode beber uma poção, e cada arma que voce pega possui\numa capacidade de ataque,ao longo do caminho voce pode recolher armas e decidi se vai\nguardar no cinto ou na mochila Quando você pega uma arma, você não esta utilizando a\nmesma para isso você prescisa manipular a mesma quando estiver em um quadrado vazio\nVocÊ só pode guardar algo no cinto cuja capacidade não ultrapasse 3\nA vida não é acumulativa ou seja ela sobrepõe um valor ao outro");

            int[] caminho = new int[27];//cria o caminho 

            int vidaTriturador = 0;
            Random vt = new Random();//Variavel aleatoria pra vida do heroi
            int vtc = vt.Next(0, 5);
            vidaTriturador = vtc;

            int ataqueTriturador = 0;
            Random at = new Random();//Variavel aleatoria pra vida do heroi
            int atc = at.Next(0, 5);
            ataqueTriturador = atc;

            int heroi = 0; // indica onde o heroi esta
            Random rh = new Random();//Variavel aleatoria pra vida do heroi
            int ih = rh.Next(1, 5);
            int vida = ih;

            int armaH = 0;//Cria a arma do heroi
            string armanow;//a arma que esta usando
            int armanowint = 0;
            int pocaoH = 0;//Cria a arma do heroi
            string pocaoanow;//cria a poçao que ele utilizara
            int pocaonowint = 0;
            //cria a potencia de vida
            /* int armaaniquiladora = 12;//cria uma arma que tem uma capicidade de ataque 5
             int machado = 13;//cria uma arma que tem uma capicidade de ataque 2
             int bastao = 14;//cria uma arma que tem uma capicidade de ataque 3
             int vidaplena = 115;//cria uma poção que tem uma capicidade de cura 5
             int vidadeinseto = 116;//cria uma poção que tem uma capicidade de cura 1
             int pocaotonica = 117;//cria uma poção que tem uma capicidade de cura 3
              int armadamorte = 15//cria uma arma que tem uma capicidade de ataque 5
int sacoradiotivo = 16;//cria uma arma que tem uma capicidade de ataque 2
int sabredeluz = 17;//cria uma arma que tem uma capicidade de ataque 4
int licordavida= 114;//cria uma poção que tem uma capicidade de cura 5
int refrescodevida = 113;//cria uma poção que tem uma capicidade de cura 2
int refrigerantefantastico = 112;//cria uma poção que tem uma capicidade de cura 3 */


            //ADICIONANDO COISAS AO CAMINHO:
            caminho[2] = 13;
            caminho[4] = 116;
            caminho[11] = 11;
            caminho[8] = 14;
            caminho[14] = 115;
            caminho[9] = 117;
            caminho[17] =16;//ataque 2
            caminho[19] =113;//cura 2
            caminho[20] = 17;//ataque 4
            caminho[24]=112;//cura4
            caminho[21] = 15;//ataque 5
            caminho[26] = 22;
            caminho[12] = 12;


            for (int r = 0; r < 27; r++)
            {
                Console.Write("Vida Original: ");
                Console.Write(vida);//exibindo a vida
                Console.WriteLine();
                Console.Write("Vida com poção:");
                Console.Write(pocaonowint);
                Console.WriteLine();
                Console.Write("Arma utilizando:");
                Console.Write(armanowint);
                Console.WriteLine();

                foreach (mochila e in mc)
                    Console.WriteLine("MOCHILA: Arma:" + e.arma + "  poção:" + e.pocao);
                //exibe os elementos da mochila
                foreach (cinto x in ct)
                    Console.WriteLine("CINTO: Arma:" + x.armac + "  Poção:" + x.pocaoc);
                //exibe os elementos do cinto
                Console.WriteLine("Digite d para seu personagen andar:");
                string movimento = Console.ReadLine();
                if (movimento == "d")
                {
                    heroi = heroi + 1;//o heroi recebe uma posição
                    if (caminho[heroi] == 22) {

                        Console.Clear();
                        Console.BackgroundColor = ConsoleColor.Cyan;
                        Console.ForegroundColor = ConsoleColor.Black;
                        Console.WriteLine("______________________________________________________________");
                        Console.WriteLine("**************************************************************");
                        Console.WriteLine("                         BATALHA                              ");
                        Console.WriteLine("______________________________________________________________");
                        Console.WriteLine("**************************************************************");
                        Console.WriteLine("Você chegou na batalha e irá lutar contra o Mensageiro da Morte");
                        Console.WriteLine("A capacidade de ataque dele é:4");
                        Console.WriteLine("A capacidade de vida dele é:3");
                        //string covst = Convert.ToString(ataqueTriturador);
                        //int conin = Convert.ToInt32(armanow); 

                        if (armanowint < 4)//Compara pra ver se a arma do triturador é maior que a arma utilizada
                        {
                            Console.Write(" O   \n-|-/* -|-\n/\\    /\\ O ");
                            Console.Write("Você Perdeu!!");
                            Console.ReadKey();
                            Environment.Exit(1);//Fechando o programa
                        }

                        if (armanowint > 4)//Compara pra ver se a arma do triturador é menor que a arma utilizada
                        {
                            Console.Write("Ganhou o jogo!!");
                            Console.ReadKey();
                            Environment.Exit(1);//Fechando o programa
                        }
                        if (armanowint == 4)//Compara pra ver se a arma do triturador é menor que a arma utilizada
                        {
                            if (pocaonowint == 0) {
                                if (vida > 3)
                                {
                                    Console.Write("Ganhou o jogo!!");
                                    Console.ReadKey();
                                    Environment.Exit(1);//Fechando o programa
                                }
                            }
                            if (pocaonowint != 0)
                            {
                                if (pocaonowint > 3)
                                {
                                    Console.Write("Ganhou o jogo!!");
                                    Console.ReadKey();
                                    Environment.Exit(1);//Fechando o programa
                                }
                                if (pocaonowint < 3)
                                {
                                    Console.Write(" O   \n-|-/* -|-\n/\\    /\\ O ");
                                    Console.Write("Você Perdeu!!");
                                    Console.ReadKey();
                                    Environment.Exit(1);//Fechando o programa
                                }
                            }
                            if (pocaonowint == vida)
                            {
                                Console.WriteLine("Empate");
                                Console.ReadKey();
                                Environment.Exit(1);//Fechando o programa
                            }

                        }
                        /*  if (armanowint)//Compara pra ver se a arma do triturador é igual a arma utilizada ai usa a poção
                           {
                               Console.Write(" O   \n-|-/* -|-\n/\\    /\\ O ");
                               Console.Write("Você Perdeu!!");
                               r = 16;
                               System.Diagnostics.Process.GetCurrentProcess().Close();//Fechando o programa
                           }*/
                    }
                    if (caminho[heroi] == 12)
                    {
                       
                        mc.Clear();
                        ct.Clear();
                        Console.BackgroundColor = ConsoleColor.Black;
                        Console.ForegroundColor = ConsoleColor.Green;

                        Console.Write("Parabens, ");
                        Console.WriteLine(nomedopersonagem);
                        Console.Write(" Você Chegou ao nivel 2, aqui suas habilidades foram zeradasa adquira novas!!,\nvocê ira enfrentar o MENSAGEIRO DA MORTE\n");

                    }
                    if (caminho[heroi] == 11)
                    {
                        Console.Clear();
                        Console.BackgroundColor = ConsoleColor.DarkMagenta;
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.WriteLine("______________________________________________________________");
                        Console.WriteLine("**************************************************************");
                        Console.WriteLine("                         BATALHA                              ");
                        Console.WriteLine("______________________________________________________________");
                        Console.WriteLine("**************************************************************");
                        Console.WriteLine("Você chegou na batalha e irá lutar contra o Triturador Cosmico");
                        Console.WriteLine("A capacidade de ataque dele é:");//numero aleatorio
                        Console.WriteLine(ataqueTriturador);
                        Console.WriteLine("A capacidade de vida dele é:");//numero aleatorio
                        Console.WriteLine(vidaTriturador);
                        //string covst = Convert.ToString(ataqueTriturador);
                        //int conin = Convert.ToInt32(armanow); 

                        if (armanowint < ataqueTriturador)//Compara pra ver se a arma do triturador é maior que a arma utilizada
                        {
                            Console.Write(" O   \n-|-/* -|-\n/\\    /\\ O ");
                            Console.Write("Você Perdeu!!");
                            Console.ReadKey();
                            Environment.Exit(1);//Fechando o programa
                        }

                        if (armanowint > ataqueTriturador)//Compara pra ver se a arma do triturador é menor que a arma utilizada
                        {
                            Console.Write("Ganhou!!");
                        }
                        if (armanowint == ataqueTriturador)//Compara pra ver se a arma do triturador é menor que a arma utilizada
                        {
                            if (pocaonowint == 0)
                            {
                                if (vida > vidaTriturador)
                                {
                                    Console.WriteLine("Você Ganhou");
                                }
                                else
                                {
                                    Console.Write("Você Perdeu!!");
                                    Console.ReadKey();
                                    Environment.Exit(1);//Fechando o programa
                                }
                            }

                            if (pocaonowint != 0)
                            {
                                if (pocaonowint > vidaTriturador)
                                {
                                    Console.Write("Ganhou!!");
                                }
                                if (pocaonowint < vidaTriturador)
                                {
                                    Console.Write(" O   \n-|-/* -|-\n/\\    /\\ O ");
                                    Console.Write("Você Perdeu!!");
                                    Console.ReadKey();
                                    Environment.Exit(1);//Fechando o programa
                                }
                            }

                        }
                       
                        //Voce  ganho/ perdeu comparando as coisas
                        Console.WriteLine();
                    }
                    else if (caminho[heroi] != 0)
                    {//se tiver alguma coisa la:

                        if ((caminho[heroi] - 100) > 0)
                        {
                            Console.WriteLine(" ___\n|_X_|");
                            if (caminho[heroi] == 115)
                            {
                                Console.WriteLine("Poção Vida Plena!!!\nCapacidade de cura 5");
                            }
                            if (caminho[heroi] == 116)
                            {
                                Console.WriteLine("Poção Vida de Inseto!!!\nCapacidade de cura 1");
                            }
                            if (caminho[heroi] == 117)
                            {
                                Console.WriteLine("Poção Vida de Tonica!!!\nCapacidade de cura 3");
                            }
                                                    
                            if (caminho[heroi] == 113)
                            {
                                Console.WriteLine("Refresco de Vida!!!\nCapacidade de cura 2");
                            }
                            if (caminho[heroi] == 112)
                            {
                                Console.WriteLine("Refrigerante Fantastico!!!\nCapacidade de cura 3");
                            }
                            if (caminho[heroi] == 114)
                            {
                                Console.WriteLine("Licor da Vida!!!\nCapacidade de cura 5");
                            }
                            Console.WriteLine("o que deseja fazer com a pocao?");//ve que é poção
                        }
                        if ((caminho[heroi] - 100) < 0)
                        {
                            Console.WriteLine(" ___\n|_¬_|");
                            if (caminho[heroi] == 16)
                            {
                                Console.WriteLine("Saco Radiotivo!!!\nCapacidade de ataque 2");
                            }
                            if (caminho[heroi] == 15)
                            {
                                Console.WriteLine("Arma da Morte!!!\nCapacidade de ataque 5");
                            }
                            if (caminho[heroi] == 17)
                            {
                                Console.WriteLine("Sabre de Luz!!!\nCapacidade de ataque 4");
                            }
                            if (caminho[heroi] == 12)
                            {
                                Console.WriteLine("Arma Aniquiladora!!!\nCapacidade de ataque 5");
                            }
                            if (caminho[heroi] == 13)
                            {
                                Console.WriteLine("Machado!!!\nCapacidade de ataque 2");
                            }
                            if (caminho[heroi] == 14)
                            {
                                Console.WriteLine("Bastão!!!\nCapacidade de ataque 3");
                            }

                            Console.WriteLine("o que deseja fazer com a arma?");//ve que é arma
                        }
                        Console.WriteLine("1.guardar\n2.Ignorar");
                        int op1 = int.Parse(Console.ReadLine());
                        if (op1 == 1)
                        {
                            Console.WriteLine("Informe a onde deseja guardar?\n1.Cinto\n2.Mochila");
                            int op11 = int.Parse(Console.ReadLine());
                            if (op11 == 1)
                            {//Ver se a arma ou poção atinge um limete de peso
                                //guardar no cinto
                                //LISTA
                                //So Vai poder guardar o elemento com potencia menor que 4
                                
                                if (caminho[heroi] == 12)
                                {
                                    Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!");
                                }
                                else if (caminho[heroi] == 115)
                                {
                                    Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!");
                                }
                                else if (caminho[heroi] == 115)
                                {
                                    Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!");
                                }
                                else if (caminho[heroi]==17) { Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!"); }
                                else if (caminho[heroi] == 112) { Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!"); }
                                else if (caminho[heroi] == 15) { Console.WriteLine("CAPACIDADE SUPERIOR AO SUPORTADO!!"); }



                                else
                                { //CASO A CAPACIDADE SEJA SUPORTADA
                                    if (caminho[heroi] == 12)
                                    {
                                        ac = 5;
                                        pc = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);//ADICIONA O ELEMENTO A LISTA
                                    }
                                                                     
                                    if (caminho[heroi] == 16)
                                    {
                                        ac = 2;
                                        pc = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }
                                    if (caminho[heroi] == 13)
                                    {
                                        ac = 2;
                                        pc = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }
                                    if (caminho[heroi] == 14)
                                    {
                                        ac = 3;
                                        pc = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }

                                    if (caminho[heroi] == 115)
                                    {
                                        pc = 5;
                                        ac = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }
                                    if (caminho[heroi] == 116)
                                    {
                                        pc = 1;
                                        ac = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }
                                   
                                    if (caminho[heroi] == 113)
                                    {
                                        pc = 2;
                                        ac = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }
                                    if (caminho[heroi] == 117)
                                    {
                                        pc = 3;
                                        ac = 0;
                                        novoc = new cinto(ac, pc);
                                        ct.Enqueue(novoc);
                                    }

                                    ac = 0;
                                    pc = 0;
                                }
                            }
                            if (op11 == 2)
                            {//guardar na mochila
                                //PILHA
                                if (caminho[heroi] == 12)
                                {
                                    armaH = 5;

                                }
                                if (caminho[heroi] == 13)
                                {
                                    armaH = 2;

                                }
                                if (caminho[heroi] == 16)
                                {
                                    armaH = 2;

                                }
                                if (caminho[heroi] == 17)
                                {
                                    armaH = 4;

                                }
                                if (caminho[heroi] == 15)
                                {
                                    armaH = 5;

                                }
                                
                                if (caminho[heroi] == 14)
                                {
                                    armaH = 3;

                                }
                                if (caminho[heroi] == 115)
                                {
                                    pocaoH = 5;

                                }
                                if (caminho[heroi] == 116)
                                {
                                    pocaoH = 1;

                                }
                                if (caminho[heroi] == 117)
                                {
                                    pocaoH = 3;

                                }
                                if (caminho[heroi] == 113)
                                {
                                    pocaoH = 2;

                                }
                                if (caminho[heroi] == 112)
                                {
                                    pocaoH = 4;

                                }
                                
                                novo = new mochila(armaH, pocaoH);
                                mc.Push(novo);

                                armaH = 0;
                                pocaoH = 0;
                            }

                        }
                        /*  if (op1 == 2)
                          {
                              //remover o item do caminho
                          }*/

                    }
                    if (caminho[heroi] == 0)//se o caminho estiver vazio 
                    {
                        Console.WriteLine(" ___\n|___|");
                        Console.WriteLine("Posição vazia!!");
                        Console.WriteLine("Deseja manipular uma arma ou uma poção?\n1.sim\n2.Não");
                        int op21 = int.Parse(Console.ReadLine());
                        if (op21 == 1)
                        {
                            Console.WriteLine("A onde está esse objeto?\n1.cinto\n2.Mochila");
                            int op211 = int.Parse(Console.ReadLine());
                            if (op211 == 1)
                            {
                                //Adicionar e exibir o que esta no cinto
                                Console.WriteLine("O elemento que deseja pegar é arma ou poção\n1.Arma\n2.Poção");//ou poderia verificar se é igual a 0
                                int poct = int.Parse(Console.ReadLine());
                                if (poct == 1)
                                {//ARMA
                                    Console.WriteLine("Qual a potencia da arma que deseja usar?");
                                    int armabu = int.Parse(Console.ReadLine());
                                    foreach (cinto x in ct)
                                    {
                                        if (armabu == x.armac)
                                        {
                                            Console.WriteLine("Arma que esta utilizando:");
                                            Console.WriteLine(Convert.ToString(x.armac));
                                            armanow = Convert.ToString(x.armac);
                                            armanowint = Convert.ToInt32(x.armac);

                                        }
                                        if (armabu != x.armac)
                                        {
                                            Console.WriteLine("Arma não encontrada!!");
                                        }

                                    }
                                }
                                if (poct == 2)
                                {//POÇÃO
                                    Console.WriteLine("Qual a potencia da poção que deseja usar?");
                                    int armabu = int.Parse(Console.ReadLine());
                                    foreach (cinto x in ct)
                                    {
                                        if (armabu == x.pocaoc)
                                        {
                                            Console.WriteLine("Poção que esta utilizando:");
                                            Console.WriteLine(Convert.ToString(x.pocaoc));
                                            armanow = Convert.ToString(x.pocaoc);
                                            pocaonowint = Convert.ToInt32(x.pocaoc);
                                        }
                                        if (armabu != x.pocaoc)
                                        {
                                            Console.WriteLine("Poção não encontrada!!");
                                        }

                                    }
                                }


                                Console.WriteLine();

                            }
                            if (op211 == 2)
                            {

                                Console.WriteLine("Você só pode manipular o elemento que está no topo.");
                                Console.WriteLine("É esse o caso?\n1.Sim\n2.Não");
                                int op2112 = int.Parse(Console.ReadLine());
                                if (op2112 == 1)
                                {
                                    Console.WriteLine("É uma poção ou uma arma\n1.Poção\n2.Arma");
                                    int op2113 = int.Parse(Convert.ToString(Console.ReadLine()));
                                    if (op2113 == 1)
                                    {//POÇAO
                                        mochila pessoaPeek = mc.Peek();
                                        Console.Write("Potencia da poção que esta utilizando: ");
                                        Console.WriteLine(pessoaPeek.pocao);

                                        pocaoanow = Convert.ToString(pessoaPeek.pocao);
                                        pocaonowint = Convert.ToInt32(pessoaPeek.pocao);

                                    }
                                    if (op2113 == 2)
                                    {//ARMA
                                        mochila pessoaPeek = mc.Peek();
                                        Console.Write("Potencia da arma que esta utilizando: ");
                                        Console.WriteLine(pessoaPeek.arma);
                                        armanow = Convert.ToString(pessoaPeek.arma);
                                        armanowint = Convert.ToInt32(pessoaPeek.pocao);

                                    }
                                }
                                if (op2112 == 2)
                                {
                                    Console.WriteLine("Retire Elementos até chegar a poção ou arma desejada:");
                                    int op21121;
                                    do
                                    {
                                        mc.Pop();
                                        mochila pessoaPeek = mc.Peek();
                                        Console.WriteLine("Poção:");
                                        Console.WriteLine(pessoaPeek.pocao);
                                        pocaoanow = Convert.ToString(pessoaPeek.pocao);
                                        pocaonowint = Convert.ToInt32(pessoaPeek.pocao);
                                        mochila elePeek = mc.Peek();
                                        Console.WriteLine("Arma:");
                                        Console.WriteLine(elePeek.arma);
                                        armanow = Convert.ToString(elePeek.arma);
                                        armanowint = Convert.ToInt32(pessoaPeek.arma);
                                        Console.WriteLine("Deseja retirar mais um elemento?\n1.Sim\n2.Não");
                                        op21121 = int.Parse(Console.ReadLine());
                                    } while (op21121 == 1);


                                }
                                //Adicionar e exibir o que esta na mochila

                            }
                        }
                        if (op21 == 2)
                        {
                            //NÃO MANIPULA NADA
                        }

                    }

                }
            }
            //

        }
    }
}
