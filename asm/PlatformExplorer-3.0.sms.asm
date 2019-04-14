; Source code created by SMS Examine V1.2a
; Size: 262144 bytes

.MEMORYMAP
SLOTSIZE $4000
SLOT 0 $0000
SLOT 1 $4000
SLOT 2 $8000
DEFAULTSLOT 2
.ENDME

.ROMBANKMAP
BANKSTOTAL 16
BANKSIZE $4000
BANKS 16
.ENDRO

; SDSC Tag:
; Name:        Platformer Explorer
; Author:      StevePro Studios
; Date:        07.04.2019
; Version:     3.00
; Description: Platformer Explorer game for the SMS Power! 2019 Competition

.BANK 0 SLOT 0
.ORG $0000

_START:
	di
	im   1
	jp   _LABEL_70_2


; Data from 6 to 7 (2 bytes)
; (only NULL-bytes)
.db $00, $00

_LABEL_8_8:
	ld   c, $BF
	di
	out  (c), l
	out  (c), h
	ei
	ret


; Data from 11 to 37 (39 bytes)
.db $00, $00, $00, $00, $00, $00, $00, "}", $D3, $BE, "|", $D6, $00, $00, $D3, $BE, $C9
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00

_IRQ_HANDLER:
	jp   _LABEL_62CA_10


; Data from 3B to 65 (43 bytes)
; (only NULL-bytes)
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

_NMI_HANDLER:
	jp   _LABEL_6300_30


; Data from 69 to 6F (7 bytes)
; (only NULL-bytes)
.db $00, $00, $00, $00, $00, $00, $00

_LABEL_70_2:
	ld   sp, $DFF0
	ld   de, $FFFC
	xor  a
	ld   (de), a
	ld   b, $03
_LABEL_7A_3:
	inc  de
	ld   (de), a
	inc  a
	djnz _LABEL_7A_3
	xor  a
	ld   hl, $C000
	ld   (hl), a
	ld   de, $C001
	ld   bc, $1FF0
	ldir
	call _LABEL_693C_4
	call _LABEL_603A_6
	ei
	call _LABEL_20A_25

; Data from 96 to 209 (372 bytes)
.db $C3, $04, $02, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $C9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $3E, $02, $CF, $C9, $3E, $00
.db $CF, $76, $18, $FD

_LABEL_20A_25:
	call _LABEL_7B2_26
	call _LABEL_7C8_28

; Data from 210 to 7B1 (1442 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.0"

_LABEL_7B2_26:
	ld   a, $00
	out  ($BF), a
	ld   a, $40
	out  ($BF), a
	ld   bc, $4000
_LABEL_7BD_27:
	ld   a, $00
	out  ($BE), a
	dec  bc
	ld   a, b
	or   c
	jp   nz, _LABEL_7BD_27
	ret

_LABEL_7C8_28:
	jp   _LABEL_603A_6


; Data from 7CB to 3FFF (14389 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.1"


.BANK 1 SLOT 1
.ORG $0000


; Data from 4000 to 6039 (8250 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.10"

_LABEL_603A_6:
	ld   hl, $0000
	push hl
	call _LABEL_615C_7
	pop  af
	ld   c, $00
_LABEL_6044_14:
	ld   hl, $608E
	ld   b, $00
	add  hl, bc
	ld   b, (hl)
	di
	ld   a, b
	out  ($BF), a
	ld   a, c
	set  7, a
	out  ($BF), a
	ei
	inc  c
	ld   a, c
	sub  $0B
	jr   c, _LABEL_6044_14
	call _LABEL_619C_15
	call _LABEL_61F7_16
	call _LABEL_6209_17
	call _LABEL_629C_20
_LABEL_6067_21:
	in   a, ($7E)
	ld   b, a
	ld   a, $80
	sub  b
	jr   c, _LABEL_6067_21
_LABEL_606F_22:
	in   a, ($7E)
	sub  $80
	jr   c, _LABEL_606F_22
_LABEL_6075_23:
	in   a, ($7E)
	ld   c, a
	in   a, ($7E)
	sub  c
	jr   nc, _LABEL_6075_23
	ld   a, c
	sub  $E7
	jr   c, _LABEL_6088_24
	ld   hl, $C35A
	ld   (hl), $80
	ret

_LABEL_6088_24:
	ld   hl, $C35A
	ld   (hl), $40
	ret


; Data from 608E to 615B (206 bytes)
.db $04, $20, $FF, $FF, $FF, $FF, $FF, $00, $00, $00, $FF, $FD, $21, $5A, $C3, $FD
.db $6E, $00, $C9, $4D, $5C, $16, $00, $21, $33, $C6, $19, $7E, $B1, $4F, $71, $F3
.db $79, $D3, $BF, $7B, $CB, $FF, $D3, $BF, $FB, $C9, $7D, $5C, $2F, $47, $16, $00
.db $21, $33, $C6, $19, $7E, $A0, $4F, $71, $F3, $79, $D3, $BF, $7B, $CB, $FF, $D3
.db $BF, $FB, $C9, $F3, $7D, $D3, $BF, $3E, $88, $D3, $BF, $FB, $C9, $F3, $7D, $D3
.db $BF, $3E, $89, $D3, $BF, $FB, $C9, $F3, $7D, $D3, $BF, $3E, $87, $D3, $BF, $FB
.db $C9, $CB, $45, $28, $04, $0E, $FB, $18, $02, $0E, $FF, $F3, $79, $D3, $BF, $3E
.db $86, $D3, $BF, $FB, $C9, $4D, $CB, $41, $28, $0F, $C5, $21, $02, $01, $CD, $A1
.db $60, $C1, $21, $35, $C6, $36, $10, $18, $0D, $C5, $21, $02, $01, $CD, $B8, $60
.db $C1, $21, $35, $C6, $36, $08, $CB, $49, $28, $14, $21, $01, $01, $CD, $A1, $60
.db $21, $36, $C6, $36, $10, $FD, $21, $35, $C6, $FD, $CB, $00, $26, $C9, $21, $01
.db $01, $CD, $B8, $60, $21, $36, $C6, $36, $08, $C9, $21, $02, $00, $39, $4E, $06
.db $00, $21, $00, $C0, $09, $CF, $21, $03, $00, $39, $7E, $D3, $BE, $C9

_LABEL_615C_7:
	ld   hl, $0002
	add  hl, sp
	ld   c, (hl)
	ld   b, $00
	ld   hl, $C010
	add  hl, bc
	rst  $8
	ld   hl, $0003
	add  hl, sp
	ld   a, (hl)
	out  ($BE), a
	ret


; Data from 6170 to 619B (44 bytes)
.db $11, $00, $C0, $0E, $BF, $F3, $ED, $59, $ED, $51, $FB, $06, $10, $0E, $BE, $ED
.db $A3, $20, $FC, $C9, $11, $10, $C0, $0E, $BF, $F3, $ED, $59, $ED, $51, $FB, $06
.db $10, $0E, $BE, $ED, $A3, $20, $FC, $C9, $7D, $D3, $BE, $C9

_LABEL_619C_15:
	ld   hl, $C41F
	ld   (hl), $00
	ret


; Data from 61A2 to 61F6 (85 bytes)
.db $3A, $1F, $C4, $D6, $40, $30, $4B, $FD, $21, $03, $00, $FD, $39, $FD, $7E, $00
.db $D6, $D1, $28, $3E, $3E, $5F, $21, $1F, $C4, $86, $4F, $3E, $C3, $CE, $00, $47
.db $FD, $5E, $00, $1D, $7B, $02, $3A, $1F, $C4, $87, $4F, $21, $9F, $C3, $06, $00
.db $09, $FD, $21, $02, $00, $FD, $39, $FD, $7E, $00, $77, $23, $FD, $21, $04, $00
.db $FD, $39, $FD, $7E, $00, $77, $FD, $21, $1F, $C4, $FD, $4E, $00, $FD, $34, $00
.db $69, $C9, $2E, $FF, $C9

_LABEL_61F7_16:
	ld   a, ($C41F)
	sub  $40
	ret  nc

	ld   bc, $C35F
	ld   hl, ($C41F)
	ld   h, $00
	add  hl, bc
	ld   (hl), $D0
	ret

_LABEL_6209_17:
	ld   hl, $7F00
	rst  $8
	ld   bc, $C35F
	ld   e, $40
_LABEL_6212_18:
	ld   a, (bc)
	out  ($BE), a
	inc  bc
	ld   d, e
	dec  d
	ld   a, d
	ld   e, a
	or   a
	jr   nz, _LABEL_6212_18
	ld   hl, $7F80
	rst  $8
	ld   bc, $C39F
	ld   e, $80
_LABEL_6226_19:
	ld   a, (bc)
	out  ($BE), a
	inc  bc
	ld   d, e
	dec  d
	ld   a, d
	ld   e, a
	or   a
	jr   nz, _LABEL_6226_19
	ret


; Data from 6232 to 629B (106 bytes)
.db $21, $57, $C3, $36, $00, $21, $57, $C3, $CB, $46, $28, $F9, $C9, $2A, $5B, $C3
.db $C9, $FD, $21, $5D, $C3, $FD, $7E, $00, $2F, $4F, $FD, $7E, $01, $2F, $47, $FD
.db $21, $5B, $C3, $FD, $7E, $00, $A1, $6F, $FD, $7E, $01, $A0, $67, $C9, $3A, $5B
.db $C3, $FD, $21, $5D, $C3, $FD, $A6, $00, $6F, $3A, $5C, $C3, $FD, $21, $5D, $C3
.db $FD, $A6, $01, $67, $C9, $FD, $21, $5B, $C3, $FD, $7E, $00, $2F, $4F, $FD, $7E
.db $01, $2F, $47, $79, $FD, $21, $5D, $C3, $FD, $A6, $00, $6F, $78, $FD, $A6, $01
.db $67, $C9, $FD, $21, $59, $C3, $FD, $6E, $00, $C9

_LABEL_629C_20:
	ld   hl, $C359
	ld   (hl), $00
	ret


; Data from 62A2 to 62C9 (40 bytes)
.db $21, $02, $00, $39, $7E, $32, $20, $C4, $21, $03, $00, $39, $7E, $32, $21, $C4
.db $C9, $21, $02, $00, $39, $4E, $F3, $79, $D3, $BF, $3E, $8A, $D3, $BF, $FB, $C9
.db $DB, $7E, $6F, $C9, $DB, $7F, $6F, $C9

_LABEL_62CA_10:
	push af
	push hl
	in   a, ($BF)
	ld   ($C358), a
	rlca
	jr   nc, _LABEL_62ED_11
	ld   hl, $C357
	ld   (hl), $01
	ld   hl, ($C35B)
	ld   ($C35D), hl
	in   a, ($DC)
	cpl
	ld   hl, $C35B
	ld   (hl), a
	in   a, ($DD)
	cpl
	inc  hl
	ld   (hl), a
	jr   _LABEL_62FB_12

_LABEL_62ED_11:
	push bc
	push de
	push iy
	ld   hl, ($C420)
	call _LABEL_65E8_13
	pop  iy
	pop  de
	pop  bc
_LABEL_62FB_12:
	pop  hl
	pop  af
	ei
	reti

_LABEL_6300_30:
	push af
	push bc
	push de
	push hl
	push iy
	ld   hl, $C359
	ld   (hl), $01
	pop  iy
	pop  hl
	pop  de
	pop  bc
	pop  af
	retn


; Data from 6313 to 65E7 (725 bytes)
.db $DD, $E5, $DD, $21, $00, $00, $DD, $39, $F5, $F5, $FD, $21, $37, $C6, $FD, $5E
.db $00, $FD, $56, $01, $FD, $6E, $02, $FD, $66, $03, $DD, $72, $FC, $DD, $75, $FD
.db $DD, $74, $FE, $DD, $36, $FF, $00, $06, $02, $DD, $CB, $FE, $3E, $DD, $CB, $FD
.db $1E, $DD, $CB, $FC, $1E, $10, $F2, $7B, $DD, $AE, $FC, $4F, $7A, $DD, $AE, $FD
.db $47, $7D, $DD, $AE, $FE, $5F, $7C, $DD, $AE, $FF, $57, $DD, $71, $FD, $DD, $70
.db $FE, $DD, $73, $FF, $DD, $36, $FC, $00, $DD, $CB, $FD, $26, $DD, $CB, $FE, $16
.db $DD, $CB, $FF, $16, $79, $DD, $AE, $FC, $4F, $78, $DD, $AE, $FD, $47, $7B, $DD
.db $AE, $FE, $5F, $7A, $DD, $AE, $FF, $57, $DD, $72, $FC, $DD, $36, $FD, $00, $DD
.db $36, $FE, $00, $DD, $36, $FF, $00, $DD, $CB, $FC, $3E, $DD, $7E, $FC, $A9, $DD
.db $77, $FC, $DD, $7E, $FD, $A8, $DD, $77, $FD, $DD, $7E, $FE, $AB, $DD, $77, $FE
.db $DD, $7E, $FF, $AA, $DD, $77, $FF, $11, $37, $C6, $21, $00, $00, $39, $01, $04
.db $00, $ED, $B0, $E1, $E5, $CB, $BC, $DD, $F9, $DD, $E1, $C9, $21, $02, $00, $39
.db $4E, $23, $46, $11, $00, $00, $FD, $21, $37, $C6, $FD, $71, $00, $FD, $70, $01
.db $FD, $73, $02, $7A, $CB, $FF, $FD, $77, $03, $C9, $F1, $C1, $D1, $D5, $C5, $F5
.db $AF, $6F, $B0, $06, $10, $20, $04, $06, $08, $79, $29, $CB, $11, $17, $30, $01
.db $19, $10, $F7, $C9, $DD, $E5, $DD, $21, $00, $00, $DD, $39, $21, $F0, $FF, $39
.db $F9, $DD, $36, $FE, $00, $DD, $36, $FF, $00, $DD, $36, $F3, $00, $DD, $36, $F4
.db $00, $DD, $6E, $05, $26, $00, $29, $29, $29, $29, $29, $29, $DD, $75, $FC, $7C
.db $F6, $78, $DD, $77, $FD, $DD, $7E, $04, $DD, $77, $FA, $DD, $36, $FB, $00, $DD
.db $CB, $FA, $26, $DD, $CB, $FB, $16, $DD, $7E, $FC, $DD, $B6, $FA, $5F, $DD, $7E
.db $FD, $DD, $B6, $FB, $57, $DD, $7E, $08, $DD, $77, $FA, $DD, $77, $F1, $DD, $36
.db $F0, $00, $6B, $62, $CF, $DD, $6E, $06, $DD, $66, $07, $7E, $DD, $77, $F2, $23
.db $DD, $75, $06, $DD, $74, $07, $DD, $7E, $06, $DD, $77, $FC, $DD, $7E, $07, $DD
.db $77, $FD, $DD, $7E, $F2, $E6, $02, $DD, $77, $F9, $DD, $7E, $F2, $0F, $0F, $E6
.db $3F, $DD, $77, $F8, $DD, $CB, $F2, $46, $CA, $40, $65, $DD, $36, $F6, $00, $DD
.db $7E, $FF, $DD, $77, $F7, $DD, $4E, $FC, $DD, $46, $FD, $03, $DD, $6E, $FC, $DD
.db $66, $FD, $6E, $DD, $7E, $F8, $C6, $02, $DD, $77, $F5, $26, $00, $7D, $DD, $B6
.db $F6, $6F, $7C, $DD, $B6, $F7, $67, $DD, $7E, $F9, $B7, $28, $3C, $DD, $71, $06
.db $DD, $70, $07, $4D, $44, $DD, $6E, $F5, $7D, $B7, $CA, $B9, $65, $E5, $69, $60
.db $DF, $E1, $DD, $35, $F1, $DD, $7E, $F1, $B7, $20, $15, $7B, $C6, $40, $5F, $7A
.db $CE, $00, $57, $E5, $C5, $6B, $62, $CF, $C1, $E1, $DD, $7E, $FA, $DD, $77, $F1
.db $3E, $01, $95, $30, $01, $03, $2D, $18, $CF, $DD, $71, $06, $DD, $70, $07, $DD
.db $75, $FE, $DD, $74, $FF, $DD, $46, $F5, $78, $B7, $CA, $C9, $65, $DD, $6E, $FE
.db $DD, $66, $FF, $DF, $DD, $35, $F1, $DD, $7E, $F1, $B7, $20, $0D, $21, $40, $00
.db $19, $5D, $54, $CF, $DD, $7E, $FA, $DD, $77, $F1, $05, $18, $DB, $DD, $7E, $F9
.db $B7, $28, $29, $DD, $CB, $F2, $56, $28, $10, $DD, $7E, $FE, $DD, $77, $F3, $DD
.db $7E, $FF, $DD, $77, $F4, $DD, $36, $F0, $01, $DD, $4E, $F2, $CB, $39, $CB, $39
.db $CB, $39, $DD, $71, $FF, $DD, $36, $FE, $00, $C3, $68, $64, $DD, $6E, $F8, $7D
.db $B7, $28, $6D, $DD, $7E, $FF, $DD, $77, $F6, $DD, $36, $F7, $00, $DD, $4E, $FC
.db $DD, $46, $FD, $DD, $75, $F5, $DD, $7E, $F5, $B7, $28, $34, $0A, $D3, $BE, $03
.db $00, $00, $00, $DD, $7E, $F6, $D3, $BE, $DD, $35, $F1, $DD, $7E, $F1, $B7, $20
.db $10, $21, $40, $00, $19, $EB, $C5, $6B, $62, $CF, $C1, $DD, $7E, $FA, $DD, $77
.db $F1, $DD, $35, $F5, $18, $D0, $DD, $71, $FE, $DD, $70, $FF, $18, $08, $18, $06
.db $DD, $71, $06, $DD, $70, $07, $DD, $CB, $F0, $46, $CA, $68, $64, $DD, $7E, $F3
.db $DD, $77, $FE, $DD, $7E, $F4, $DD, $77, $FF, $DD, $36, $F0, $00, $C3, $68, $64
.db $DD, $F9, $DD, $E1, $C9

_LABEL_65E8_13:
	jp   (hl)


; Data from 65E9 to 693B (851 bytes)
.db $FD, $21, $04, $00, $FD, $39, $FD, $6E, $00, $FD, $66, $01, $29, $29, $29, $29
.db $29, $CB, $F4, $CF, $C1, $DD, $E1, $DD, $E5, $C5, $DD, $4E, $00, $DD, $23, $DD
.db $46, $00, $DD, $23, $C5, $06, $04, $11, $22, $C4, $DD, $4E, $00, $DD, $23, $CB
.db $01, $30, $43, $CB, $01, $38, $3B, $DD, $7E, $00, $DD, $23, $EB, $57, $E6, $03
.db $87, $87, $87, $5F, $7A, $16, $00, $FD, $21, $22, $C4, $FD, $19, $EB, $FE, $03
.db $38, $3E, $FE, $10, $38, $14, $FE, $13, $38, $3B, $FE, $20, $38, $0C, $FE, $23
.db $38, $38, $FE, $40, $38, $04, $FE, $43, $38, $39, $67, $DD, $6E, $00, $DD, $23
.db $18, $0A, $26, $00, $18, $06, $CB, $01, $9F, $6F, $26, $FF, $C5, $06, $08, $7D
.db $CB, $04, $38, $05, $DD, $7E, $00, $DD, $23, $12, $13, $10, $F2, $C1, $18, $31
.db $21, $00, $FF, $18, $15, $21, $FF, $FF, $18, $10, $DD, $66, $00, $2E, $00, $DD
.db $23, $18, $07, $DD, $66, $00, $2E, $FF, $DD, $23, $C5, $06, $08, $FD, $7E, $00
.db $FD, $23, $AD, $CB, $04, $38, $05, $DD, $7E, $00, $DD, $23, $12, $13, $10, $ED
.db $C1, $05, $C2, $18, $66, $11, $08, $00, $4B, $21, $22, $C4, $06, $04, $E5, $7E
.db $D3, $BE, $19, $10, $FA, $E1, $23, $0D, $20, $F2, $C1, $0B, $78, $B1, $C2, $0D
.db $66, $C9, $21, $03, $00, $39, $5E, $2B, $6E, $CD, $0B, $67, $C3, $39, $67, $F1
.db $E1, $D1, $D5, $E5, $F5, $CD, $13, $67, $C3, $39, $67, $21, $03, $00, $39, $5E
.db $2B, $6E, $CD, $99, $5F, $EB, $C9, $F1, $E1, $D1, $D5, $E5, $F5, $CD, $9C, $5F
.db $EB, $C9, $F1, $E1, $D1, $D5, $E5, $F5, $C3, $13, $67, $21, $03, $00, $39, $5E
.db $2B, $6E, $7D, $07, $9F, $67, $7B, $07, $9F, $57, $7C, $AA, $17, $7C, $F5, $17
.db $30, $06, $97, $95, $6F, $9F, $94, $67, $CB, $7A, $28, $06, $97, $93, $5F, $9F
.db $92, $57, $CD, $9C, $5F, $F1, $D0, $47, $97, $95, $6F, $9F, $94, $67, $78, $C9
.db $17, $EB, $D0, $97, $95, $6F, $9F, $94, $67, $C9, $91, $0B, $94, $0B, $97, $0B
.db $9A, $0B, $9D, $0B, $A0, $0B, $A3, $0B, $A6, $0B, $A9, $0B, $AC, $0B, $AF, $0B
.db $B1, $0B, $B3, $0B, $B5, $0B, $B7, $0B, $B9, $0B, $BB, $0B, $BD, $0B, $BF, $0B
.db $C1, $0B, $14, $B3, $EC, $B3, $C4, $B4, $9C, $B5, $74, $B6, $4C, $B7, $24, $B8
.db $FC, $B8, $D4, $B9, $AC, $BA, $00, $80, $D8, $80, $B0, $81, $88, $82, $60, $83
.db $38, $84, $10, $85, $E8, $85, $C0, $86, $98, $87, $70, $88, $48, $89, $20, $8A
.db $F8, $8A, $D0, $8B, $A8, $8C, $80, $8D, $58, $8E, $30, $8F, $08, $90, $E0, $90
.db $B8, $91, $90, $92, $68, $93, $40, $94, $18, $95, $F0, $95, $C8, $96, $A0, $97
.db $78, $98, $50, $99, $28, $9A, $00, $9B, $D8, $9B, $B0, $9C, $88, $9D, $60, $9E
.db $38, $9F, $10, $A0, $E8, $A0, $00, $80, $D8, $80, $B0, $81, $88, $82, $60, $83
.db $38, $84, $10, $85, $E8, $85, $C0, $86, $98, $87, $70, $88, $48, $89, $20, $8A
.db $F8, $8A, $D0, $8B, $A8, $8C, $80, $8D, $58, $8E, $30, $8F, $08, $90, $E0, $90
.db $B8, $91, $90, $92, $68, $93, $40, $94, $18, $95, $F0, $95, $C8, $96, $A0, $97
.db $78, $98, $50, $99, $28, $9A, $00, $9B, $D8, $9B, $B0, $9C, $88, $9D, $60, $9E
.db $38, $9F, $10, $A0, $E8, $A0, $E8, $83, $16, $85, $33, $86, $4B, $87, $4A, $88
.db $2A, $89, $3E, $8A, $5B, $8B, $73, $8C, $72, $8D, $52, $8E, $00, $80, $EF, $80
.db $F1, $81, $E6, $82, $00, $80, $00, $80, $00, $80, $96, $89, $00, $80, $25, $86
.db $7A, $0D, $8D, $0D, $A0, $0D, $B3, $0D, $C6, $0D, $D9, $0D, $EC, $0D, $FF, $0D
.db $12, $0E, $25, $0E, $38, $0E, $4B, $0E, $5E, $0E, $71, $0E, $84, $0E, $97, $0E
.db $AA, $0E, $BD, $0E, $D0, $0E, $E3, $0E, $F7, $0E, $05, $0F, $0D, $0F, $1E, $0F
.db $2D, $0F, $3B, $0F, $49, $0F, $57, $0F, $66, $0F, $7F, $0F, $99, $0F, $AB, $0F
.db $B3, $0F, $B3, $0F, $B5, $0F, $CB, $0F, $E2, $0F, $F7, $0F, $B3, $0F, $0F, $10
.db $00, $80, $FF, $80, $11, $82, $16, $83, $6C, $6D, $7C, $00, $00, $00, $00, $01
.db $01, $01, $02, $02, $02, $02, $02, $02, $02, $01, $02, $02, $02, $03, $03, $03
.db $03, $03, $03, $F5, $F8, $F9, $FA, $FB, $FC, $FC, $FD, $FD, $FD, $FE, $FE, $FE
.db $FF, $FF, $FF, $FF, $01, $01, $02, $02, $03, $03, $04, $04, $05, $05, $05, $05
.db $05, $05, $05, $05, $05, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $01, $01, $00, $00, $00, $01, $01, $01, $01, $01, $01, $01, $01
.db $01, $01, $01, $01, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $01
.db $01, $01, $01, $01, $01, $01, $02, $02, $02, $02, $02, $02, $02, $02, $02, $02
.db $02, $02, $02, $02, $02, $84, $01, $8C, $01, $94, $01, $9C, $01, $D8, $3A, $DD
.db $3A, $13, $14, $09, $14, $09, $14, $13, $14, $0C, $12, $04, $20, $08, $08, $01
.db $00, $00, $80

_LABEL_693C_4:
	ld   bc, $01F9
	ld   a, b
	or   c
	jr   z, _LABEL_694B_5
	ld   de, $C442
	ld   hl, $6743
	ldir
_LABEL_694B_5:
	ret


; Data from 694C to 7FFF (5812 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.1A"


.BANK 2 SLOT 2
.ORG $0000


; Data from 8000 to BFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.20"


.BANK 3
.ORG $0000


; Data from C000 to FFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.30"


.BANK 4
.ORG $0000


; Data from 10000 to 13FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.40"


.BANK 5
.ORG $0000


; Data from 14000 to 17FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.50"


.BANK 6
.ORG $0000


; Data from 18000 to 1BFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.60"


.BANK 7
.ORG $0000


; Data from 1C000 to 1FFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.70"


.BANK 8
.ORG $0000


; Data from 20000 to 23FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.80"


.BANK 9
.ORG $0000


; Data from 24000 to 27FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.90"


.BANK 10
.ORG $0000


; Data from 28000 to 2BFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.A0"


.BANK 11
.ORG $0000


; Data from 2C000 to 2FFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.B0"


.BANK 12
.ORG $0000


; Data from 30000 to 33FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.C0"


.BANK 13
.ORG $0000


; Data from 34000 to 37FFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.D0"


.BANK 14
.ORG $0000


; Data from 38000 to 3BFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.E0"


.BANK 15
.ORG $0000


; Data from 3C000 to 3FFFF (16384 bytes)
.incbin "PlatformExplorer-3.0.sms.dat.F0"

