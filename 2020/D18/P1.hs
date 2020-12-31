import System.Environment
import Text.Parsec
import Text.Parsec.Token
import Text.Parsec.Expr
import Text.Parsec.Language

data Expr = Val Integer | Duo Duop Expr Expr deriving Show

data Duop = Plus | Minus | Div | Mul deriving Show

def = emptyDef{
          reservedOpNames = ["+", "-", "*", "/"]
      }

TokenParser{ parens = m_parens
           , reservedOp = m_reservedOp
           , integer = m_integer
           , whiteSpace = m_whiteSpace } = makeTokenParser def

exprparser = buildExpressionParser table term <?> "expresssion"
table = [ [Infix (m_reservedOp "+" >> return (Duo Plus)) AssocLeft
          ,Infix (m_reservedOp "-" >> return (Duo Minus)) AssocLeft
          ,Infix (m_reservedOp "*" >> return (Duo Mul)) AssocLeft
          ,Infix (m_reservedOp "/" >> return (Duo Div)) AssocLeft]
        ]
term = m_parens exprparser
       <|> fmap Val m_integer

evalExpr expr = case expr of
                    Val x -> x
                    Duo Plus e1 e2 -> (evalExpr e1) + (evalExpr e2)
                    Duo Minus e1 e2 -> (evalExpr e1) - (evalExpr e2)
                    Duo Mul e1 e2 -> (evalExpr e1) * (evalExpr e2)
                    Duo Div e1 e2 -> div (evalExpr e1) (evalExpr e2)

eval line = case (parse exprparser "" line) of
                Left _ -> -1
                Right val -> evalExpr val

main = do
    args <- getArgs
    content <- readFile $ head args
    print $ sum $ map eval $ lines content
