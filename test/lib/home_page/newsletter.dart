import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

class Newsletter extends StatelessWidget {
  const Newsletter({super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.only(top: 40),
      width: 1000,
      height: 600,
      decoration: const BoxDecoration(
          gradient: LinearGradient(colors: [
        Color.fromARGB(255, 250, 132, 183),
        Color.fromRGBO(236, 218, 254, 1),
      ], begin: Alignment.topCenter, end: Alignment.bottomCenter)),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          const FaIcon(
            FontAwesomeIcons.envelope,
            size: 100,
            color: Colors.black,
          ),
          const SizedBox(
            height: 10,
          ),
          const Text(
            "Receba todas as",
            style: TextStyle(
                fontSize: 45, fontWeight: FontWeight.bold, fontFamily: "Anton"),
          ),
          const Text("promocoes",
              style: TextStyle(
                  fontSize: 45,
                  fontWeight: FontWeight.bold,
                  fontFamily: "Anton")),
          const Text(
            "Quer receber nossas",
            style: TextStyle(
                color: Colors.white, fontSize: 30, fontWeight: FontWeight.w200),
          ),
          const Text("ofertas? Cadastre-se e",
              style: TextStyle(
                  color: Colors.white,
                  fontSize: 30,
                  fontWeight: FontWeight.w200)),
          const Text("comece a recebe-las!",
              style: TextStyle(
                  color: Colors.white,
                  fontSize: 30,
                  fontWeight: FontWeight.w200)),
          const SizedBox(
            height: 10,
          ),
          Container(
            width: 250,
            height: 40,
            decoration: const BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.all(Radius.circular(20))),
            child: const TextField(
              decoration: InputDecoration(
                  border: InputBorder.none,
                  contentPadding: EdgeInsets.all(10),
                  hintText: "Email"),
            ),
          ),
          const SizedBox(
            height: 10,
          ),
          Container(
            width: 250,
            height: 40,
            decoration: const BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.all(Radius.circular(20))),
            child: const TextField(
              decoration: InputDecoration(
                  border: InputBorder.none,
                  contentPadding: EdgeInsets.all(10),
                  hintText: "Nome"),
            ),
          ),const SizedBox(height: 5,),
          Container(
            height: 30,
            width: 104,
            decoration: const BoxDecoration(
              color: Colors.black,
              borderRadius: BorderRadius.all(Radius.circular(20))
            ),
            child: TextButton(
                onPressed: () => {},
                child: const Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text("Quero receber!",
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 10
                    ),),
                    FaIcon(FontAwesomeIcons.heart,size: 10,color: Colors.white,)
                  ],
                ),
                
                ),
          )
        ],
      ),
    );
  }
}
