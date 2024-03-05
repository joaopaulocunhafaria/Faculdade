import 'package:flutter/material.dart';

class Testimonial extends StatelessWidget {
  const Testimonial({super.key});
  //const Color.fromRGBO(250, 235, 215, 1),

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 10000,
      padding: EdgeInsets.only(bottom: 20),
      color: const Color.fromRGBO(250, 235, 215, 1),
      child: Column(
        children: [
          const SizedBox(height: 20),
          const Text(
            "Elas usam",
            style: TextStyle(
                fontSize: 25,
                color: Colors.black,
                fontWeight: FontWeight.bold,
                fontFamily: 'Anton'),
          ),
          const Text(
            "Nossa loja",
            style: TextStyle(
                fontSize: 32,
                color: Color.fromRGBO(255, 95, 165, 1),
                fontWeight: FontWeight.w600,
                fontFamily: 'Anton'),
          ),
          Container(
            padding: const EdgeInsets.all(10),
            width: 320,
            height: 250,
            decoration: BoxDecoration(
                color: const Color.fromARGB(255, 255, 255, 255),
                borderRadius: BorderRadius.circular(20),
                border: Border.all(
                    color: const Color.fromRGBO(255, 95, 165, 1), width: 2)),
            child: Column(
              children: [
                Row(
                  children: [
                    Container(
                      width: 70,
                      height: 70,
                      decoration: BoxDecoration(
                          image: const DecorationImage(
                              image: AssetImage("assets/images/user.jpg"),
                              fit: BoxFit.fill),
                          borderRadius: BorderRadius.circular(50),
                          border: Border.all(
                              color: const Color.fromRGBO(255, 95, 165, 1),
                              width: 1)),
                    )
                  ],
                ),
                const SizedBox(
                  height: 10,
                ),
                const Text(
                    "A loja possui um otimo atendimento e nao consigo pensar em outra melhor",
                    style: TextStyle(
                      fontSize: 15
                    ),),
                const SizedBox(
                  height: 10,
                ),
                const Text(
                  "Fernanda da Silva",
                  style: TextStyle(
                      color: Color.fromRGBO(0, 0, 0, 1),
                      fontSize: 25,
                      fontWeight: FontWeight.bold),
                ),
                const SizedBox(
                  height: 5,
                ),
                const Text(
                  "Divinopolis",
                  style: TextStyle(
                      color:   Color.fromRGBO(255, 95, 165, 1),
                      fontSize: 30,
                      fontWeight: FontWeight.bold),
                )
              ],
            ),
          )
        ],
      ),
    );
  }
}
