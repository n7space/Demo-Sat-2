$SEDS_CONVERTER --from SEDS --to SDL --aux-models ASN.1,InterfaceView --skip-validation -i resources/test_cross_reference.xml --out $TEST_OUTPUT_DIR/funinterfaces.xml --iv-config config.xml --asn1-filepath-prefix ./ --acn-filepath-prefix ./ --sdl-filepath-prefix ./