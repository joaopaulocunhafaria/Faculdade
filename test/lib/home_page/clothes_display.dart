import 'package:flutter/material.dart';

class ClothesDisplay extends StatelessWidget {
  const ClothesDisplay({super.key});

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        Container(
            height: 150,
            child: Image.asset(
              "assets/clothesImages/saia.jpg",
              fit: BoxFit.fitWidth,
            )),
        const Center(
          child: Text(
            "Saia",
            style: TextStyle(fontSize: 18),
          ),
        ),
        const Center(
          child: Text('R\$800.0',
              style: TextStyle(
                color: Color.fromRGBO(255, 95, 165, 1),
                fontWeight: FontWeight.w100,
                fontSize: 20.0,
                fontFamily: 'Anton',
              )),
        ),
        const Center(
          child: Text("Cartao e pix",
              style: TextStyle(
                color: Color.fromRGBO(106, 102, 102, 1),
               
                fontSize: 15.0,
              )),
        )
      ],
    );
  }
}
