; part 1: Warm Up with Lambada Procedures
(define mxbFormula
	(lambda (m x b) ; params
		(+ (* m x) b)))

(display "Part 1; y = mx + b: ")
(display (mxbFormula 1 2 1))
(newline)
(newline)

; Part 2: Warmup with Anonymous Lambda Procedures (Quadratic Formula)
; sqrt(b^2 - 4ac)
(define discriminant
	(lambda (a b c) ; params
		(sqrt (- (* b b) (* 4 a c)))))

; (-b +- discriminant)/2a
(define quadratic
	(lambda (a b c) ; params
		(list (/ (- (- b) (discriminant a b c)) (* 2 a)) (/ (+ (- b) (discriminant a b c)) (* 2 a)))))

(display "Part 2; Quadratic Formula: ")
(display (quadratic 1 2 0))
(newline)
(newline)

; Part 3: Mapping (Dot Product)
(define dots 
	(lambda (X Y)
		(* X Y)))

(define dotproduct
	(lambda (L1 L2)
		(apply + (map dots L1 L2))))
;apply + (map part3 (list 1 2 3) (list 4 5 6)))

(display "Part 3; Mapping: ")
(display (dotproduct (list 1 2 3) (list 4 5 6)))
(newline)
(newline)

; Part 4: Working with Lists
; czr which returns the last item in the list
(define czr 
	(lambda (L)
		(if (null? (cdr L))
			(car L)
			(czr (cdr L)))))

; cxr that returns everything except the last item in the list
(define cxr
	(lambda (L)
		(if (null? (cdr L))
			'()
			(cons (car L) (cxr (cdr L))))))

(display "Part 4; List Work: ")
(newline)
(display "czr procedure: ")
(display (czr (list 1 2 3)))
(newline)
(display "cxr procedure: ")
(display (cxr (list 1 2 3)))
(newline)