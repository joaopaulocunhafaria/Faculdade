import 'package:flutter/material.dart';

class SlideImage extends StatelessWidget {
  const SlideImage({super.key, required this.image, required this.body});

  final String image;
  final Widget body;

  @override
  Widget build(BuildContext context) {
    return AnimatedContainer(
      
      
      duration: const Duration(milliseconds: 500),
      curve: Curves.bounceIn,
      margin: const EdgeInsets.only(left: 10, right: 10, bottom: 6),
      decoration: BoxDecoration(
        
           
          borderRadius: BorderRadius.circular(20),
          image: DecorationImage(fit: BoxFit.cover, image: AssetImage(image))),
          child:  body
    );
  }
}
