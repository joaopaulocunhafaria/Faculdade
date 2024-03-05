import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:sign_in_button/sign_in_button.dart';
import 'package:test/home_page/home_page.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  TextEditingController _emailController = TextEditingController();
  TextEditingController _passwordController = TextEditingController();

  final FirebaseAuth _auth = FirebaseAuth.instance;

  User? _user;

  @override
  void initState() {
    super.initState();

    _auth.authStateChanges().listen((event) {
      setState(() {
        _user = event;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      body: _user==null?_loginPage():_homePage(),
    );
  }

  Widget _loginPage() {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Color.fromRGBO(255, 95, 165, 1),
        title: Container(
          color: const Color.fromRGBO(255, 95, 165, 1),
          child:
              const Row(mainAxisAlignment: MainAxisAlignment.center, children: [
            Text(
              "",
              selectionColor: Colors.black,
            )
          ]),
        ),
      ),
      body: Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            colors: [
              Color.fromRGBO(255, 95, 165, 1),
              Color.fromRGBO(236, 218, 254, 1)
            ],
            begin: Alignment.topCenter,
            end: Alignment.bottomCenter,
          ),
        ),
        child: Center(
          child: Padding(
            padding: const EdgeInsets.fromLTRB(16.0, 10.0, 16.0, 16.0),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.start,
              children: [
                const SizedBox(
                  height: 10,
                ),
                const Text(
                  "MINHA LOJA",
                  style: TextStyle(
                      color: Colors.white,
                      fontSize: 45,
                      fontWeight: FontWeight.bold),
                ),
                const SizedBox(height: 160.0),
                TextField(
                  controller: _emailController,
                  decoration: InputDecoration(
                    labelText: 'Email',
                    border: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(10.0),
                    ),
                  ),
                ),
                SizedBox(height: 16.0),
                TextField(
                  controller: _passwordController,
                  obscureText: true,
                  decoration: InputDecoration(
                    labelText: 'Senha',
                    border: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(10.0),
                    ),
                  ),
                ),
                SizedBox(height: 24.0),
                ElevatedButton(
                  onPressed: () {
                    // Implementar a lógica de autenticação aqui
                    //Aqui sera onde devera ser implementado
                    //a logica de verificacao de formulario ccom
                    //o firebase
                    String email = _emailController.text;
                    String password = _passwordController.text;

                    // Exemplo simples de validação
                    if (email.isNotEmpty && password.isNotEmpty) {
                      Navigator.push(
                        context,
                        MaterialPageRoute(builder: (context) => HomePage()),
                      );
                    } else {
                      print('Por favor, preencha todos os campos.');
                    }
                  },
                  child: Text('Login'),
                ),
                Container(
                  width: 100,
                  decoration:
                      BoxDecoration(borderRadius: BorderRadius.circular(20.0)),
                  child: SignInButton(
                    Buttons.google,
                    text: "Google",
                    onPressed: _handleGoogleSingIn,
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(
                          10.0), // Ajusta según tus preferencias
                    ),
                    elevation: 3,
                  ),
                ),
                SizedBox(height: 16.0),
                GestureDetector(
                  onTap: () {
                    // Navegar para a tela de cadastro ao clicar no texto
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => HomePage()),
                    );
                  },
                  child: Container(
                    color: Colors.transparent,
                    child: Text(
                      'Cadastrar-se',
                      textAlign: TextAlign.center,
                      style: TextStyle(
                        color: Colors.blue,
                        decoration: TextDecoration.underline,
                      ),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  Widget _homePage() {
    return HomePage();
  }


  void _handleGoogleSingIn() {
    try {
      GoogleAuthProvider _googleAuthProvider = GoogleAuthProvider();
      _auth.signInWithProvider(_googleAuthProvider);
    } catch (error) {
      print("++++++++++++++++++++++++++++++++++++++++++++");
    }
  }
}
